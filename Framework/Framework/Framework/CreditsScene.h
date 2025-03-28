#pragma once
#include "Scene.h"

class CreditsScene : public Scene {
protected:

public:
	CreditsScene() {
		nextScene = "Credits";
		//Constructor TODO -> load scores
	}
	~CreditsScene() = default; //Destructor TODO -> save scores
	void Update() override;
	void Render() override;
};