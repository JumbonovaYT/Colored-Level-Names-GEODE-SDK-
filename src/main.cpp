#include <Geode/Geode.hpp>
using namespace geode::prelude;


/*GET SETTINGS*/
/*starting with main difficulties*/
auto easycolor = Mod::get()->getSettingValue<cocos2d::ccColor3B>("Easy Level Color");
auto normalcolor = Mod::get()->getSettingValue<cocos2d::ccColor3B>("Normal Level Color");
auto hardcolor = Mod::get()->getSettingValue<cocos2d::ccColor3B>("Hard Level Color");
auto hardercolor = Mod::get()->getSettingValue<cocos2d::ccColor3B>("Harder Level Color");
auto insanecolor = Mod::get()->getSettingValue<cocos2d::ccColor3B>("Insane Level Color");

/*now onto demon difficulties*/

auto easydemoncolor = Mod::get()->getSettingValue<cocos2d::ccColor3B>("Easy Demon Level Color");
auto mediumdemoncolor = Mod::get()->getSettingValue<cocos2d::ccColor3B>("Medium Demon Level Color");
auto harddemoncolor = Mod::get()->getSettingValue<cocos2d::ccColor3B>("Hard Demon Level Color");
auto insanedemoncolor = Mod::get()->getSettingValue<cocos2d::ccColor3B>("Insane Demon Level Color");
auto extremedemoncolor = Mod::get()->getSettingValue<cocos2d::ccColor3B>("Extreme Demon Level Color");
		
/*now for the other difficulties*/

auto nacolor = Mod::get()->getSettingValue<cocos2d::ccColor3B>("N/A Level Color");
auto autocolor = Mod::get()->getSettingValue<cocos2d::ccColor3B>("Auto Level Color");


/*Edit level names in the level info layer*/

#include <Geode/modify/LevelInfoLayer.hpp>
class $modify(ColoredNameLevelInfoLayer, LevelInfoLayer) { 
	bool init(GJGameLevel* level, bool info) {

		if (!LevelInfoLayer::init(level, info)) {
			return false;
		}

		/*get the nodes in the level info page*/

		auto title = this->getChildByID("title-label");
		auto difficulty = this->getChildByID("difficulty-sprite");

		/*now onto editing the level info layer*/
		/*NORMAL DIFFICULTIES*/


		if (isSpriteFrameName(difficulty, "difficulty_05_btn_001.png")) {
			typeinfo_cast<CCRGBAProtocol*>(title)->setColor(insanecolor);
		};
		if (isSpriteFrameName(difficulty, "difficulty_04_btn_001.png")) {
			typeinfo_cast<CCRGBAProtocol*>(title)->setColor(hardercolor);
		};
		if (isSpriteFrameName(difficulty, "difficulty_03_btn_001.png")) {
			typeinfo_cast<CCRGBAProtocol*>(title)->setColor(hardcolor);
		};
		if (isSpriteFrameName(difficulty, "difficulty_02_btn_001.png")) {
			typeinfo_cast<CCRGBAProtocol*>(title)->setColor(normalcolor);
		};
		if (isSpriteFrameName(difficulty, "difficulty_01_btn_001.png")) {
			typeinfo_cast<CCRGBAProtocol*>(title)->setColor(easycolor);
		};


		/*DEMON DIFFICULTIES*/


		if (isSpriteFrameName(difficulty, "difficulty_07_btn2_001.png")) {
			typeinfo_cast<CCRGBAProtocol*>(title)->setColor(easydemoncolor);
		};
		if (isSpriteFrameName(difficulty, "difficulty_08_btn2_001.png")) {
			typeinfo_cast<CCRGBAProtocol*>(title)->setColor(mediumdemoncolor);
		};
		if (isSpriteFrameName(difficulty, "difficulty_06_btn2_001.png")) {
			typeinfo_cast<CCRGBAProtocol*>(title)->setColor(harddemoncolor);
		};
		if (isSpriteFrameName(difficulty, "difficulty_09_btn2_001.png")) {
			typeinfo_cast<CCRGBAProtocol*>(title)->setColor(insanedemoncolor);
		};
		if (isSpriteFrameName(difficulty, "difficulty_10_btn2_001.png")) {
			typeinfo_cast<CCRGBAProtocol*>(title)->setColor(extremedemoncolor);
		};


		/*OTHER DIFFICULTIES*/


		if (isSpriteFrameName(difficulty, "difficulty_auto_btn_001.png")) {
			typeinfo_cast<CCRGBAProtocol*>(title)->setColor(autocolor);
		};
		if (isSpriteFrameName(difficulty, "difficulty_00_btn_001.png")) {
			typeinfo_cast<CCRGBAProtocol*>(title)->setColor(nacolor);
		};

	return true;

	}
};