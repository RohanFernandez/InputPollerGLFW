///////////////////////////Input class from Rohan Fernandez rohan31f@gmail.com
///////////////////////////https://github.com/RohanFernandez
///////////////////////////Please, rate the functionality in the repository if you found it helpful https://github.com/RohanFernandez/InputPollerGLFW 

#include <iostream>
#include <input.h>

int main()
{
	GLFWwindow* l_pWindow = nullptr;
	FRETBUZZ::Input* l_pInput = nullptr;


	if (!glfwInit())
		return -1;
	l_pWindow = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!l_pWindow)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(l_pWindow);

	l_pInput = FRETBUZZ::Input::initialize(l_pWindow); /// Create Input singleton

	while (!glfwWindowShouldClose(l_pWindow))
	{

		l_pInput->Update(); /// Input class update per frame
		/* Poll for and process events */
		glfwPollEvents();

		if (FRETBUZZ::Input::IsKeyDown(GLFW_KEY_F))
		{
			std::cout << "F Key Down\n";
		}
		if (FRETBUZZ::Input::IsKeyPutUp(GLFW_KEY_Z))
		{
			std::cout << "Z Key UP\n";
		}

		if (FRETBUZZ::Input::IsMouseBtnPutUp(GLFW_MOUSE_BUTTON_1))
		{
			std::cout << "Mouse left button clicked\n";
		}

		int l_iMouseScrollValue = FRETBUZZ::Input::GetMouseScroll();
		if (l_iMouseScrollValue > 0)
		{
			std::cout << "Mouse Scrolled Forwards\n";
		}
		else if (l_iMouseScrollValue < 0)
		{
			std::cout << "Mouse Scrolled Backwards\n";
		}

		/* Render here */
		//glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(l_pWindow);
		

		
	}

	l_pInput->destroy();/// Destroy Input singleton
	glfwTerminate();
	return 0;
}