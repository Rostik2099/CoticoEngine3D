#include "Renderer.h"
#include "Core/CEngine.h"

Renderer::Renderer(CEngine* engine)
{
	this->engine = engine;
	glViewport(0, 0, 800, 800);
	glEnable(GL_DEPTH_TEST);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& imguiIO = ImGui::GetIO(); (void)imguiIO;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(engine->GetWindow()->GetGLWindow(), true);
	ImGui_ImplOpenGL3_Init("#version 330");
}

void Renderer::Render()
{
	glClearColor(0.07f, 0.13f, 0.17f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	for (auto mesh : World::Get()->GetMeshComps())
	{
		mesh->Draw(*engine->GetCamera());
	}

	EditorUIManager::GetUIManager()->Render();

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	glfwSwapBuffers(engine->GetWindow()->GetGLWindow());
}

Renderer::~Renderer() 
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}
