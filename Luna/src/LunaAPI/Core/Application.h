#pragma once

#include "Lunapch.h"

#include "LunaAPI/Core/Defines.h"
#include "LunaAPI/Core/Window.h" 
#include "LunaAPI/Event/Event.h"
#include "LunaAPI/Event/ApplicationEvent.h"
#include "LunaAPI/ImGui/UI.h"
#include "LunaAPI/Core/DeltaTime.h"
#include "LunaAPI/Renderer/Framebuffer.h"

#include "GLFW/glfw3.h"


namespace Luna {

	class Application
	{
	public:
		UI m_ImGuiLayer;

	public:
		Application(const std::string name);
		virtual ~Application();

		//API for the main.cpp (app dev)
		void ShowImGuiDemoWindow();
		float GetElapesedRuntime();
		bool IsRunning();
		void Clear(float r, float g, float b, float transparent); //Step 1
		void Render(std::shared_ptr<Texture>& texture, glm::mat4 transform); //Step 2
		void Display(); //Step 3
		void DrawUI(); //Step 4
		void Update(); //Step 5
		static void BuildUI(); //Outside of class in its own namespace?


	//Used internally, use on own risk
	public:
		inline static Application& Get() { return *s_Instance; }
		WindowInterface& GetWindow() const { return *m_Window; }
		void OnGUIClose();


	private:
		void OnEvent(Event& event);
		bool OnWindowCloseEvent(WindowCloseEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);

		void UpdateGUI();
		void EndRendering();
		void UpdateWindow();

	private:
		static Application* s_Instance;
		bool m_IsRunning = true;
		float m_LastFrameTime = 0.0f;
		std::unique_ptr<WindowInterface> m_Window; //Window
		unsigned int m_FrameBuffer;
	};
}