#include "Overlay.h"


void S_Overlay::render(Editor * p_CurrentMainEditor)
{


	if(S_LevelEditor::get_LevelEditor().get_SelectedObjectType() == Block100x100)
	{
		S_Resourcemanager::get_Resourcemanager().apply_Surface(p_CurrentMainEditor->get_Position()->x,p_CurrentMainEditor->get_Position()->y,S_Resourcemanager::get_Resourcemanager().get_Surface("100x100BlockSelected"),S_Resourcemanager::get_Resourcemanager().get_Surface("Screen"));
	}

	S_Resourcemanager::get_Resourcemanager().apply_Surface(0,0,S_Resourcemanager::get_Resourcemanager().get_Surface("FullyUnselectedMenue"),S_Resourcemanager::get_Resourcemanager().get_Surface("Screen"));

	if(this->b_startSelected == true)
	{
		S_Resourcemanager::get_Resourcemanager().apply_Surface(0,40,S_Resourcemanager::get_Resourcemanager().get_Surface("StartChoice"),S_Resourcemanager::get_Resourcemanager().get_Surface("Screen"));
	}
	else if(this->b_choiceSelected == true)
	{
		S_Resourcemanager::get_Resourcemanager().apply_Surface(97,40,S_Resourcemanager::get_Resourcemanager().get_Surface("ChoiceChoice"),S_Resourcemanager::get_Resourcemanager().get_Surface("Screen"));
	}

}


void S_Overlay::handle_Events(SDL_Event even)
{
	if (even.type == SDL_MOUSEBUTTONDOWN)
	{
		if(even.button.button == SDL_BUTTON_LEFT)
		{
			if(even.button.x >=  0 && even.button.x <= 97 && even.button.y >= 0 && even.button.y <= 40)
			{
				if(this->b_startSelected == true)
				{
					this->b_startSelected = false;
					this->b_nothingSelected = true;
				}
				else
				{
				this->b_startSelected = true;
				this->b_nothingSelected = false;
				this->b_choiceSelected = false;
				}
			}
			else if(even.button.x > 97 && even.button.x <= 224 && even.button.y >= 0 && even.button.y <= 40)
			{
				if(this->b_choiceSelected == true)
				{
					this->b_choiceSelected = false;
					this->b_nothingSelected = true;
				}
				else
				{
				this->b_startSelected = false;
				this->b_nothingSelected = false;
				this->b_choiceSelected = true;
				}
			}
		}
	}
}

void S_Overlay::debugFunctionShow()
{
	if(b_nothingSelected == true)
	{
		cout << "Nichts ausgewaehlt" << endl;
	}

	if(b_choiceSelected == true)
	{
		cout << "Choice ausgewählt" << endl;
	}

	if(b_startSelected == true)
	{
		cout << "Start ausgewählt" << endl;
	}
}