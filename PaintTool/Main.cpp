#include <GLFW/glfw3.h>
#include "Canvas.h"

int main()
{
	/*
	 * 프로그램 흐름
	 *	Proc 1: GLFW 초기화
	 *  Proc 2: Windo 생성
	 *	Proc 3: OpenGL 컨텍스트 설정
	 *  Proc 4: Canvas 생성
	 *  Proc 5: 메인 루프
	 *	Proc 6: GLFW 종료
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
