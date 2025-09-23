#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <GLFW/glfw3.h>
#include "Canvas.h"
#include "PenPainter.h"
#include "BrushPainter.h"

Canvas* gCanvas = nullptr;

void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	ImGui_ImplGlfw_MouseButtonCallback(window, button, action, mods);

	ImGuiIO& io = ImGui::GetIO();
	if (io.WantCaptureMouse)
	{
		return;
	}

	if (!gCanvas)
	{
		return;
	}

	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	if (button == GLFW_MOUSE_BUTTON_LEFT)
	{
		if (action == GLFW_PRESS)
			gCanvas->OnMouseDown(xpos, ypos);
		else if (action == GLFW_RELEASE)
			gCanvas->OnMouseUp();
	}
}

void CursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
	if (gCanvas)
		gCanvas->OnMouseMove(xpos, ypos);
}

int main()
{
	/*
	 * 프로그램 흐름
	 *	Proc 1: GLFW 초기화
	 *  Proc 2: Windo 생성
	 *	Proc 3: OpenGL 컨텍스트 설정
	 *	Proc 4: ImGui 초기화
	 *	Proc 5: 투영 행렬 설정
	 *  Proc 6: Canvas 생성
	 *  Proc 7: 콜백 함수 등록
	 *  Proc 8: 메인 루프
	 *	Proc 9: GLFW 종료
	 */

	if (!glfwInit())
	{
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(1920, 1080, "Paint Tool", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 130");

	/*
	 * 투영 행렬 설정
	 *	- 화면 좌표계를 사용
	 *	- (0,0) at bottom-left
	 *	- (width,height) at top-right
	 */
	
	int width, height;
	glfwGetWindowSize(window, &width, &height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	Canvas canvas;
	gCanvas = &canvas;

	glfwSetMouseButtonCallback(window, MouseButtonCallback);
	glfwSetCursorPosCallback(window, CursorPosCallback);

	BrushPainter* brush = new BrushPainter();
	brush->SetSize(10.f);
	canvas.SetPainter(brush);

	while (!glfwWindowShouldClose(window))
	{
		/*
		 * 메인 루프
		 *  Proc 1: Canvas 그리기
		 *  Proc 2: 화면 갱신
		 *  Proc 3: 이벤트 처리
		 */
		glfwPollEvents();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();


		if (ImGui::IsMouseClicked(ImGuiMouseButton_Right))
			ImGui::OpenPopup("Context Menu");

		if (ImGui::BeginPopup("Context Menu"))
		{
			if (ImGui::BeginMenu("Color"))
			{
				ImGui::EndMenu();
			}
			ImGui::EndPopup();
		}

		canvas.Draw();

		ImGui::Render();
		glViewport(0, 0, width, height);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();

    return 0;
}
