#pragma once

#include "Game.h"

void CreateTestScene(Game* game);

int main()
{
	Game* game = Game::Instance();
	game->Init();

	CreateTestScene(game);

	game->Run();

	return 0;
}

void CreateTestScene(Game* game)
{
	GameObject* go = new GameObject();
	go->GetTransform()->Translate(glm::vec3(0.0f, 0.0f, -5.0f));
	go->GetTransform()->Rotate(0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
	go->GetTransform()->Scale(glm::vec3(1.25f, 1.0f, 1.0f));
	float red = 0.0f, green = 0.0f, blue = 0.0f;
	std::vector<float> verts = {
		//positions				
		-0.5f, -0.5f, -0.5f,	red, green, blue,
		+0.5f, -0.5f, -0.5f,	red, green, blue,
		+0.5f, +0.5f, -0.5f,	red, green, blue,
		+0.5f, +0.5f, -0.5f,	red, green, blue,
		-0.5f, +0.5f, -0.5f,	red, green, blue,
		-0.5f, -0.5f, -0.5f,	red, green, blue,

		-0.5f, -0.5f, +0.5f,	red, green, blue,
		+0.5f, -0.5f, +0.5f,	red, green, blue,
		+0.5f, +0.5f, +0.5f,	red, green, blue,
		+0.5f, +0.5f, +0.5f,	red, green, blue,
		-0.5f, +0.5f, +0.5f,	red, green, blue,
		-0.5f, -0.5f, +0.5f,	red, green, blue,

		-0.5f, +0.5f, +0.5f,	red, green, blue,
		-0.5f, +0.5f, -0.5f,	red, green, blue,
		-0.5f, -0.5f, -0.5f,	red, green, blue,
		-0.5f, -0.5f, -0.5f,	red, green, blue,
		-0.5f, -0.5f, +0.5f,	red, green, blue,
		-0.5f, +0.5f, +0.5f,	red, green, blue,

		+0.5f, +0.5f, +0.5f,	red, green, blue,
		+0.5f, +0.5f, -0.5f,	red, green, blue,
		+0.5f, -0.5f, -0.5f,	red, green, blue,
		+0.5f, -0.5f, -0.5f,	red, green, blue,
		+0.5f, -0.5f, +0.5f,	red, green, blue,
		+0.5f, +0.5f, +0.5f,	red, green, blue,

		-0.5f, -0.5f, -0.5f,	red, green, blue,
		+0.5f, -0.5f, -0.5f,	red, green, blue,
		+0.5f, -0.5f, +0.5f,	red, green, blue,
		+0.5f, -0.5f, +0.5f,	red, green, blue,
		-0.5f, -0.5f, +0.5f,	red, green, blue,
		-0.5f, -0.5f, -0.5f,	red, green, blue,

		-0.5f, +0.5f, -0.5f,	red, green, blue,
		+0.5f, +0.5f, -0.5f,	red, green, blue,
		+0.5f, +0.5f, +0.5f,	red, green, blue,
		+0.5f, +0.5f, +0.5f,	red, green, blue,
		-0.5f, +0.5f, +0.5f,	red, green, blue,
		-0.5f, +0.5f, -0.5f,	red, green, blue
	};
	Mesh* mesh1 = new Mesh();
	mesh1->Generate(verts);
	go->SetMesh(mesh1);
	game->AddGameObject(go);

	GameObject* go2 = new GameObject();
	go2->GetTransform()->Translate(glm::vec3(-1.0f, 0.0f, -2.0f));
	go2->GetTransform()->Rotate(20.0f, glm::vec3(0.1f, 0.1f, -1.0f));
	go2->GetTransform()->Scale(glm::vec3(1.0f, 0.60f, 1.9f));
	Mesh* mesh2 = new Mesh();
	mesh2->Generate(verts);
	go2->SetMesh(mesh2);
	game->AddGameObject(go2);

	GameObject* go3 = new GameObject();
	go3->GetTransform()->Translate(glm::vec3(1.0f, 0.0f, 1.0f));
	go3->GetTransform()->Rotate(45.0f, glm::vec3(1.0f, 1.0f, 1.0f));
	go3->GetTransform()->Scale(glm::vec3(0.25f, 0.25f, 0.25f));
	Mesh* mesh3 = new Mesh();
	mesh3->Generate(verts);
	go3->SetMesh(mesh2);
	game->AddGameObject(go3);
}