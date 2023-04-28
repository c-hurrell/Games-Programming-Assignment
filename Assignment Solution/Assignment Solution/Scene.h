
#include "Debug.h"
#include "SDL.h"
#include "Object.h"

using namespace std;

class Scene
{
public:
	Scene(string scene_name = "default");
	~Scene();
	void Start();
	void Update();
	void Render(SDL_Renderer* renderer);
	// All the GameObjects
	vector<GameObject*> gameObjects;
	void AddGameObject(GameObject gameObject);

	// GameObject Functions
	void FindObjectWithTag(string tag);
	void DestroyObjectsWithTag(string tag);
	void DestroyObject(GameObject* object);

	void CreateGameObject(string gmObjTag = "default");
	
};
