#include "SaveGame.h"


int SaveGame::highScore;
int SaveGame::gold;
int SaveGame::jump=1;
int SaveGame::xSpeed=5;
bool SaveGame::kunaiDrop;
bool SaveGame::potionDrop;
bool SaveGame::bombDrop;
std::iostream SaveGame::saveFile(&read);
std::filebuf SaveGame::read;
std::filebuf SaveGame::write;
std::string SaveGame::line;

void SaveGame::save()
{
	write.open("save.txt",std::ios::out|std::ios::trunc);
	saveFile.rdbuf(&write);
	saveFile << std::to_string(highScore) <<'\n';
	saveFile << std::to_string(gold) << '\n';
	saveFile << std::to_string(jump) << '\n';
	saveFile << std::to_string(xSpeed) << '\n';
	//mettre bool
	if (kunaiDrop) {
		saveFile << "true" << '\n';
	}
	else {
		saveFile << "false" << '\n';
	}
	if (potionDrop) {
		saveFile << "true" << '\n';
	}
	else {
		saveFile << "false" << '\n';
	}
	if (bombDrop) {
		saveFile << "true" << '\n';
	}
	else {
		saveFile << "false" << '\n';
	}
	saveFile.unsetf(std::ios::trunc);
	write.close();
	

}

bool SaveGame::load()
{
	std::vector<std::string> value;
	read.open("save.txt", std::ios::in );
	saveFile.rdbuf(&read);
	if (read.is_open()) {
		while (std::getline(saveFile, line)) {

			if (line != "") {

				value.push_back(line);

				
			}
			else {
				read.close();
				return false;
			}
		}
		if (value.size() < 4) { 
			read.close();
			return false;
		}
		highScore = std::stoi(value[0]);
		gold = std::stoi(value[1]);
		jump = std::stoi(value[2]);
		xSpeed = std::stoi(value[3]);
		if (value[4].compare("true") == 0) {
			kunaiDrop = true;
		}
		else {
			kunaiDrop = false;
		}
		if (value[5].compare("true") == 0) {
			potionDrop = true;
		}
		else {
			potionDrop = false;
		}
		if (value[6].compare("true") == 0) {
			bombDrop = true;
		}
		else {
			bombDrop = false;
		}
		read.close();
		return true;
	}
	return false;
}

int SaveGame::getHighScore()
{
	
	return highScore;
}

void SaveGame::setHighScore(int score)
{
	highScore = score;
}
int SaveGame::getGold()
{
	return gold;
}
void SaveGame::setGold(int goldNb)
{
	gold = goldNb;
}

int SaveGame::getjump()
{
	return jump;
}

void SaveGame::setjump(int nbJump)
{
	jump = nbJump;
}

int SaveGame::getXSpeed()
{
	return xSpeed;
}

void SaveGame::setXSpeed(int speed)
{
	xSpeed = speed;
}
bool SaveGame::getKunaiDrop()
{
	return kunaiDrop;
}
void SaveGame::setKunaiDrop(bool drop)
{
	kunaiDrop = drop;
}
bool SaveGame::getPotionDrop()
{
	return potionDrop;
}
void SaveGame::setPotionDrop(bool drop)
{
	potionDrop = drop;
}
bool SaveGame::getBombDrop()
{
	return bombDrop;
}
void SaveGame::setBombDrop(bool drop)
{
	bombDrop = drop;
}