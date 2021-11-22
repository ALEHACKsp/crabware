#include "menu.h"
#include "font_awesome.h"
#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "gui.h"


#include <fstream>
#include "vars.h"
#include "pasteshit/game.h"
#include "includes.h"




#define SECTION

static const char* current_resource = "NONE";
extern ImFont* Consolas;
Vars cVars;

void Separator(const char* Id)
{
	ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(68, 68, 68, 255));
	ImGui::BeginChild(Id, ImVec2(ImGui::GetContentRegionAvailWidth(), 1), true);
	ImGui::EndChild();
	ImGui::PopStyleColor();
}

void Menu::Render()
{
	ImGui::Begin("CrapWare", 0, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings);
	ImGui::Columns(2, "##OurColumns", true);
	ImGui::SetColumnOffset(1, 255); 

	if (ImGui::Button(ICON_FA_ROCKET" Movement", ImVec2(240, 45)))
		Menu::Tab = 1;
	ImGui::Spacing();
	if (ImGui::Button(ICON_FA_BOMB" Combat", ImVec2(240, 45)))
		Menu::Tab = 2;
	ImGui::Spacing();
	if (ImGui::Button(ICON_FA_BUG" Misc", ImVec2(240, 45)))
		Menu::Tab = 3;

	
	{
		ImGui::SetCursorPosX(255 / 2.41);
		ImGui::SetCursorPosY(ImGui::GetWindowHeight() - 30);
		ImGui::Text("sxck1337");
		ImGui::NextColumn();
	}

	SECTION;
	{
		if ((Menu::Tab == 0))
		{
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::SetCursorPosX(400);
			ImGui::Text("// Totally not pasted Crab Game Internal");
		}
	}
	SECTION;
	{
		if ((Menu::Tab == 1))
		{
			ImGui::Checkbox("Moon Gravity", &cVars.moon);

			if ((cVars.moon == true)) {

				Game::MoonGravity(true);
			}
			else if ((cVars.moon == false)) {

				Game::MoonGravity(false);
			}

			ImGui::Checkbox("Always Sprint", &cVars.sprint);

			if ((cVars.sprint == true)) {

				Game::AlwaysSprint(true);
			}
			else if ((cVars.sprint == false)) {

				Game::AlwaysSprint(false);
			}

			ImGui::Checkbox("Airjump", &cVars.airjump);

			if ((cVars.airjump == true)) {

				Game::InfiniteJump(true);
			}
			else if ((cVars.airjump == false)) {

				Game::InfiniteJump(false);
			}
		}
	}
	SECTION;
	{
		if ((Menu::Tab == 2))
		{
			ImGui::Checkbox("Fast Punch", &cVars.punch);

			if ((cVars.punch == true)) {

				Game::FastPunch(true);
			}
			else if ((cVars.punch == false)) {

				Game::FastPunch(false);
			}
		}
	}
	SECTION;
	{
		if ((Menu::Tab == 3))
		{
			ImGui::Checkbox("No Cam Shake", &cVars.camshake);

			if ((cVars.camshake == true)) {

				Game::NoCameraShake(true);
			}
			else if ((cVars.camshake == false)) {

				Game::NoCameraShake(false);
			}
		}
	}



	ImGui::End();
}

void Menu::Theme()
{
	ImGui::GetMouseCursor();
	ImGui::SetMouseCursor(ImGuiMouseCursor_Arrow);
	ImGui::GetIO().WantCaptureMouse = Menu::IsMenuOpen;
	ImGui::GetIO().MouseDrawCursor = Menu::IsMenuOpen;

	auto& style = ImGui::GetStyle();

	style.WindowMinSize = ImVec2(910, 420);
	style.FrameBorderSize = 0;
	style.WindowRounding = 0;
	style.TabRounding = 0;
	style.ScrollbarRounding = 0;
	style.FramePadding = ImVec2(6.5, 6.5);
	style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style.ItemInnerSpacing = ImVec2(8, 8);
	style.DisplayWindowPadding.x = 0;
	style.ChildBorderSize = 0.99;
	style.WindowBorderSize = 0;

	style.Colors[ImGuiCol_TitleBg] = ImColor(22, 96, 184, 255);
	style.Colors[ImGuiCol_TitleBgActive] = ImColor(22, 96, 184, 255);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(15, 15, 15, 50);

	style.Colors[ImGuiCol_WindowBg] = ImColor(15, 15, 15, 255);			

	style.Colors[ImGuiCol_Button] = ImColor(29, 28, 29, 255);		
	style.Colors[ImGuiCol_ButtonActive] = ImColor(54, 53, 55);	     
	style.Colors[ImGuiCol_ButtonHovered] = ImColor(54, 53, 55);		 

	style.Colors[ImGuiCol_CheckMark] = ImColor(255, 255, 255, 255);		

	style.Colors[ImGuiCol_FrameBg] = ImColor(36, 37, 36, 255);
	style.Colors[ImGuiCol_FrameBgActive] = ImColor(36, 37, 36, 255);
	style.Colors[ImGuiCol_FrameBgHovered] = ImColor(36, 37, 36, 255);
	
	style.Colors[ImGuiCol_Header] = ImColor(33, 33, 33, 255);	
	style.Colors[ImGuiCol_HeaderActive] = ImColor(34, 33, 35);
	style.Colors[ImGuiCol_HeaderHovered] = ImColor(35, 35, 35, 100);

	style.Colors[ImGuiCol_ResizeGrip] = ImColor(51, 49, 50, 255);		  
	style.Colors[ImGuiCol_ResizeGripActive] = ImColor(54, 53, 55);		
	style.Colors[ImGuiCol_ResizeGripHovered] = ImColor(51, 49, 50, 255);		

	style.Colors[ImGuiCol_SliderGrab] = ImColor(249, 79, 49, 255);
	style.Colors[ImGuiCol_SliderGrabActive] = ImColor(249, 79, 49, 255);

	style.Colors[ImGuiCol_Border] = ImColor(54, 54, 54);

	style.Colors[ImGuiCol_ChildBg] = ImColor(32, 32, 32, 255);
	style.Colors[ImGuiCol_Separator] = ImColor(68, 68, 68, 255);
	style.Colors[ImGuiCol_SeparatorActive] = ImColor(68, 68, 68, 255);
	style.Colors[ImGuiCol_SeparatorHovered] = ImColor(68, 68, 68, 255);
}