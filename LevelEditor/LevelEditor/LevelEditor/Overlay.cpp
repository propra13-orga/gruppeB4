#include "Overlay.h"


void S_Overlay::render(Editor * p_CurrentMainEditor)
{
	if(S_LevelEditor::get_LevelEditor().get_SelectedObjectType() == Block100x100)
	{
		S_Resourcemanager::get_Resourcemanager().apply_Surface(p_CurrentMainEditor->get_Position()->x,p_CurrentMainEditor->get_Position()->y,S_Resourcemanager::get_Resourcemanager().get_Surface("100x100BlockSelected"),S_Resourcemanager::get_Resourcemanager().get_Surface("Screen"));
	}
}