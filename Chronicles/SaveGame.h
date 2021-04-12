#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
	class SaveGame
	{
	public:
		static void save();
		static bool load();
		static int getHighScore();
		static void setHighScore(int score);
		static int getGold();
		static void setGold(int goldNb);
		static int getjump();
		static void setjump(int nbJump);
		static int getXSpeed();
		static void setXSpeed(int speed);
		static bool getKunaiDrop();
		static void setKunaiDrop(bool drop);
		static bool getPotionDrop();
		static void setPotionDrop(bool drop);
		static bool getBombDrop();
		static void setBombDrop(bool drop);
	private:
		static int highScore;
		static int gold;
		static int jump;
		static int xSpeed;
		static bool kunaiDrop;
		static bool potionDrop;
		static bool bombDrop;
		
		static std::iostream saveFile;
		static std::filebuf read;
		static std::filebuf write;
		static std::string line;
		
	};
	

