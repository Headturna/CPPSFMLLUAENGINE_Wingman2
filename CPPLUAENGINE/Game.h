#pragma once

class Game
{
private:
	sf::RenderWindow window;
	sf::View view;
	sf::Event ev;
	float dt;
	sf::Clock dtClock;
	sf::Clock globalClock;

	lua_State* L;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosWorld;

	sf::RectangleShape background;

	std::stack<std::string> states;

	std::vector<sf::Texture*> textures;
	std::vector<sf::Sprite*> sprites;

	std::vector<TileMap*> tileMaps;
	//Access z first! when fixing culling

	//Spritesheet class

	void initWindow();
	void initView();
	void initImgui();
	void initDt();
	void initLua();
	void registerLuaFunctions();
	void initBackground();

	//Getter
	inline const float& getDT() const { return this->dt; };

	//Setter
	inline void setDT(const float dt) { this->dt = dt; };

	//Functions
	void updateMousePositions();

public:
	Game();
	~Game();

	//Functions
	const sf::RenderWindow& getWindow() const;

	void updatePollWindowEvents();
	void updateStates();
	void updateTilemaps();
	void update();

	void renderBackground();
	void renderSprites();
	void renderTilemaps();
	void render();

	void run();

	//Core FUNCTIONS
	static int closeWindow(lua_State* L);
	static int cpp_setViewCenter(lua_State* L);
	static int luaDT(lua_State* L);
	static int cpp_time(lua_State* L);
	static int setState(lua_State* L);
	static int endState(lua_State* L);
	
	//Sprite related
	static int cpp_getMousePosScreen(lua_State* L);
	static int cpp_getMousePosWindow(lua_State* L);
	static int cpp_getMousePosWorld(lua_State* L);
	static int cpp_setBackgroundTexture(lua_State* L);
	static int newTexture(lua_State* L);
	static int newTextureBatch(lua_State* L);
	static int newSprite(lua_State* L);
	static int moveSprite(lua_State* L);
	static int cpp_setSpritePosition(lua_State* L);
	static int cpp_getSpritePosition(lua_State* L);
	static int cpp_rotateSprite(lua_State* L);
	static int cpp_setSpriteRotation(lua_State* L);
	static int cpp_getSpriteRotation(lua_State* L);
	static int cpp_setSpriteOrigin(lua_State* L);
	static int cpp_getSpriteOriginX(lua_State* L);
	static int cpp_getSpriteOriginY(lua_State* L);
	static int cpp_setSpriteScale(lua_State* L);
	static int cpp_getSpriteScale(lua_State* L);
	static int cpp_setSpriteTexture(lua_State* L);

	//Tile related
	static int cpp_addTile(lua_State* L);

	//Input
	static int keyPressed(lua_State* L);
	static int cpp_mousePressed(lua_State* L);

	static int testFunc(lua_State* L);
};

