#pragma once

#include "Game.h"

void CreateTestScene(Game* game);
void CreateRandomTestScene(Game* game);

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
	float red = 1.0f, green = 0.0f, blue = 0.0f;
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
		//positions				// tex coords
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
	std::vector<float> mixedVerts = {
		//positions				//colors			//texture UVs
		-0.5f, -0.5f, -0.5f,	red, green, blue,	0.0f, 0.0f,
		+0.5f, -0.5f, -0.5f,	red, green, blue,	1.0f, 0.0f,
		+0.5f, +0.5f, -0.5f,	red, green, blue,	1.0f, 1.0f,
		+0.5f, +0.5f, -0.5f,	red, green, blue,	1.0f, 1.0f,
		-0.5f, +0.5f, -0.5f,	red, green, blue,	0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	red, green, blue,	0.0f, 0.0f,

		-0.5f, -0.5f, +0.5f,	red, green, blue,	0.0f, 0.0f,
		+0.5f, -0.5f, +0.5f,	red, green, blue,	1.0f, 0.0f,
		+0.5f, +0.5f, +0.5f,	red, green, blue,	1.0f, 1.0f,
		+0.5f, +0.5f, +0.5f,	red, green, blue,	1.0f, 1.0f,
		-0.5f, +0.5f, +0.5f,	red, green, blue,	0.0f, 1.0f,
		-0.5f, -0.5f, +0.5f,	red, green, blue,	0.0f, 0.0f,

		-0.5f, +0.5f, +0.5f,	red, green, blue,	1.0f, 0.0f,
		-0.5f, +0.5f, -0.5f,	red, green, blue,	1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	red, green, blue,	0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	red, green, blue,	0.0f, 1.0f,
		-0.5f, -0.5f, +0.5f,	red, green, blue,	0.0f, 0.0f,
		-0.5f, +0.5f, +0.5f,	red, green, blue,	1.0f, 0.0f,

		+0.5f, +0.5f, +0.5f,	red, green, blue,	1.0f, 0.0f,
		+0.5f, +0.5f, -0.5f,	red, green, blue,	1.0f, 1.0f,
		+0.5f, -0.5f, -0.5f,	red, green, blue,	0.0f, 1.0f,
		+0.5f, -0.5f, -0.5f,	red, green, blue,	0.0f, 1.0f,
		+0.5f, -0.5f, +0.5f,	red, green, blue,	0.0f, 0.0f,
		+0.5f, +0.5f, +0.5f,	red, green, blue,	1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,	red, green, blue,	0.0f, 1.0f,
		+0.5f, -0.5f, -0.5f,	red, green, blue,	1.0f, 1.0f,
		+0.5f, -0.5f, +0.5f,	red, green, blue,	1.0f, 0.0f,
		+0.5f, -0.5f, +0.5f,	red, green, blue,	1.0f, 0.0f,
		-0.5f, -0.5f, +0.5f,	red, green, blue,	0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,	red, green, blue,	0.0f, 1.0f,

		-0.5f, +0.5f, -0.5f,	red, green, blue,	0.0f, 1.0f,
		+0.5f, +0.5f, -0.5f,	red, green, blue,	1.0f, 1.0f,
		+0.5f, +0.5f, +0.5f,	red, green, blue,	1.0f, 0.0f,
		+0.5f, +0.5f, +0.5f,	red, green, blue,	1.0f, 0.0f,
		-0.5f, +0.5f, +0.5f,	red, green, blue,	0.0f, 0.0f,
		-0.5f, +0.5f, -0.5f,	red, green, blue,	0.0f, 1.0f
	};

	GameObject* go = new GameObject();
	go->GetTransform()->Translate(glm::vec3(0.0f, 0.0f, -10.0f));
	go->GetTransform()->Rotate(85.0f, glm::vec3(1.0f, 1.0f, 1.0f));
	go->GetTransform()->Scale(glm::vec3(1.25f, 1.0f, 1.0f));
	go->AddNewMesh();
	go->GetMesh()->Generate(mixedVerts, Shader::MIXED);
	game->AddGameObject(go);

	GameObject* go2 = new GameObject();
	go2->GetTransform()->Translate(glm::vec3(-2.0f, 1.0f, -5.0f));
	go2->GetTransform()->Rotate(45.0f, glm::vec3(-1.0f, 0.0f, -1.0f));
	go2->GetTransform()->Scale(glm::vec3(1.0f, 2.0f, 2.0f));
	go2->AddNewMesh();
	go2->GetMesh()->Generate(textureVerts, Shader::TEXTURE);
	game->AddGameObject(go2);

	GameObject* go3 = new GameObject();
	go3->GetTransform()->Translate(glm::vec3(2.0f, 1.0f, -1.0f));
	go3->GetTransform()->Rotate(25.0f, glm::vec3(1.0f, 0.0f, -1.0f));
	go3->GetTransform()->Scale(glm::vec3(0.5f, 0.25f, 0.5f));
	go3->AddNewMesh();
	go3->GetMesh()->Generate(colorVerts, Shader::COLOR);
	game->AddGameObject(go3);

}

void CreateRandomTestScene(Game* game)
{
	std::vector<float> verts = {
		//positions				// tex coords
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

	srand((unsigned)time(NULL));
	for (int i = 0; i < 40; i++)
	{
		float a = rand() % 20;
		glm::vec3 pos(rand() % 50 - 25, rand() % 50 - 25, rand() % 50 - 25);
		float deg = rand() % 361;
		glm::vec3 rotAxis(rand() % 20 - 10, rand() % 20 - 10, rand() % 20 - 10);
		glm::vec3 scale(rand() % 6 + 2, rand() % 6 + 2, rand() % 6 + 2);

		GameObject* go = new GameObject();
		go->GetTransform()->SetPosition(pos);
		go->GetTransform()->Rotate(deg, rotAxis);
		go->GetTransform()->Scale(scale);
		go->AddNewMesh();
		go->GetMesh()->Generate(verts, Shader::TEXTURE);
		game->AddGameObject(go);
	}

	
}