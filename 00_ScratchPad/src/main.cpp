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
	float red = 1.5f, green = 0.5f, blue = 0.2f;
	std::vector<float> colorVerts = {
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
	std::vector<float> textureVerts = {
		//positions				// text coords
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f,
		+0.5f, -0.5f, -0.5f,	1.0f, 0.0f,
		+0.5f, +0.5f, -0.5f,	1.0f, 1.0f,
		+0.5f, +0.5f, -0.5f,	1.0f, 1.0f,
		-0.5f, +0.5f, -0.5f,	0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f,

		-0.5f, -0.5f, +0.5f,	0.0f, 0.0f,
		+0.5f, -0.5f, +0.5f,	1.0f, 0.0f,
		+0.5f, +0.5f, +0.5f,	1.0f, 1.0f,
		+0.5f, +0.5f, +0.5f,	1.0f, 1.0f,
		-0.5f, +0.5f, +0.5f,	0.0f, 1.0f,
		-0.5f, -0.5f, +0.5f,	0.0f, 0.0f,

		-0.5f, +0.5f, +0.5f,	1.0f, 0.0f,
		-0.5f, +0.5f, -0.5f,	1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f,
		-0.5f, -0.5f, +0.5f,	0.0f, 0.0f,
		-0.5f, +0.5f, +0.5f,	1.0f, 0.0f,

		+0.5f, +0.5f, +0.5f,	1.0f, 0.0f,
		+0.5f, +0.5f, -0.5f,	1.0f, 1.0f,
		+0.5f, -0.5f, -0.5f,	0.0f, 1.0f,
		+0.5f, -0.5f, -0.5f,	0.0f, 1.0f,
		+0.5f, -0.5f, +0.5f,	0.0f, 0.0f,
		+0.5f, +0.5f, +0.5f,	1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f,
		+0.5f, -0.5f, -0.5f,	1.0f, 1.0f,
		+0.5f, -0.5f, +0.5f,	1.0f, 0.0f,
		+0.5f, -0.5f, +0.5f,	1.0f, 0.0f,
		-0.5f, -0.5f, +0.5f,	0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f,

		-0.5f, +0.5f, -0.5f,	0.0f, 1.0f,
		+0.5f, +0.5f, -0.5f,	1.0f, 1.0f,
		+0.5f, +0.5f, +0.5f,	1.0f, 0.0f,
		+0.5f, +0.5f, +0.5f,	1.0f, 0.0f,
		-0.5f, +0.5f, +0.5f,	0.0f, 0.0f,
		-0.5f, +0.5f, -0.5f,	0.0f, 1.0f
	};

	GameObject* go = new GameObject();
	go->GetTransform()->Translate(glm::vec3(0.0f, 0.0f, -10.0f));
	go->GetTransform()->Rotate(85.0f, glm::vec3(1.0f, 1.0f, 1.0f));
	go->GetTransform()->Scale(glm::vec3(1.25f, 1.0f, 1.0f));
	Mesh* mesh1 = new Mesh();
	mesh1->Generate(textureVerts, std::vector<int>{3, 2});
	mesh1->SetMaterialShader(Shader::TEXTURE);
	go->SetMesh(mesh1);
	game->AddGameObject(go);

	GameObject* go2 = new GameObject();
	go2->GetTransform()->Translate(glm::vec3(-2.0f, 1.0f, -5.0f));
	go2->GetTransform()->Rotate(45.0f, glm::vec3(-1.0f, 0.0f, -1.0f));
	go2->GetTransform()->Scale(glm::vec3(1.0f, 2.0f, 2.0f));
	Mesh* mesh2 = new Mesh();
	mesh2->Generate(colorVerts, std::vector<int>{3, 3});
	mesh2->SetMaterialShader(Shader::COLOR);
	go2->SetMesh(mesh2);
	game->AddGameObject(go2);

	GameObject* go3 = new GameObject();
	go3->GetTransform()->Translate(glm::vec3(2.0f, 1.0f, -1.0f));
	go3->GetTransform()->Rotate(25.0f, glm::vec3(1.0f, 0.0f, -1.0f));
	go3->GetTransform()->Scale(glm::vec3(0.5f, 0.25f, 0.5f));
	Mesh* mesh3 = new Mesh();
	mesh3->Generate(textureVerts, std::vector<int>{3, 2});
	mesh3->SetMaterialShader(Shader::TEXTURE);
	go3->SetMesh(mesh3);
	game->AddGameObject(go3);

}