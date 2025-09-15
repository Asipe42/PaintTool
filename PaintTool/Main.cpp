#include <GLFW/glfw3.h>
#include "Canvas.h"

Canvas* gCanvas = nullptr;

void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	if (!gCanvas) return;

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

// 커서 이동 콜백
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
	 *  Proc 4: Canvas 생성
	 *  Proc 5: 콜백 함수 등록
	 *  Proc 6: 메인 루프
	 *	Proc 7: GLFW 종료
	 */

	if (!glfwInit())
	{
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(800, 600, "Paint Tool", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	Canvas canvas;
	gCanvas = &canvas;

	glfwSetMouseButtonCallback(window, MouseButtonCallback);
	glfwSetCursorPosCallback(window, CursorPosCallback);

	// temp
	Brush redBrush(5.0f, 1.0f, { 1.0f, 0.0f, 0.0f }, 1.0f);
	canvas.SetBrush(redBrush);

	while (!glfwWindowShouldClose(window))
	{
		/*
		 * 메인 루프
		 *  Proc 1: Canvas 그리기
		 *  Proc 2: 화면 갱신
		 *  Proc 3: 이벤트 처리
		 */

		canvas.Draw();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

    return 0;
}
