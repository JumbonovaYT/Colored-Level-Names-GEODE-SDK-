#include <Geode/Geode.hpp>
using namespace geode::prelude;

/*Edit level names in the level info layer*/

#include <Geode/modify/LevelInfoLayer.hpp>
class $modify(ColoredNameLevelInfoLayer, LevelInfoLayer) { 
	bool init(GJGameLevel* level, bool info) {

		if (!LevelInfoLayer::init(level, info)) {
			return false;
		}

		/*before we start, lets check if this feature is enabled. if it isn't, we'll stop this from running.*/
		bool enabled = Mod::get()->getSettingValue<bool>("Change Title of Levels");

		if (enabled) {

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

			/*get the nodes in the level info layer*/

			auto title = this->getChildByID("title-label");
			auto difficulty = this->getChildByID("difficulty-sprite");

			/*less crashes*/
			if (!title || !difficulty) {
				return true;
			};

			/*now onto editing the level info layer*/
			/*NORMAL DIFFICULTIES*/


			if (isSpriteFrameName(difficulty, "difficulty_05_btn_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_5_0_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_5_0_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(insanecolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_04_btn_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_4_0_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_4_0_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(hardercolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_03_btn_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_3_0_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_3_0_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(hardcolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_02_btn_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_2_0_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_2_0_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(normalcolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_01_btn_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_1_0_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_1_0_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(easycolor);
			};


			/*DEMON DIFFICULTIES*/


			if (isSpriteFrameName(difficulty, "difficulty_07_btn2_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_7_1_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_7_1_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(easydemoncolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_08_btn2_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_8_1_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_8_1_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(mediumdemoncolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_06_btn2_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_6_1_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_6_1_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(harddemoncolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_09_btn2_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_9_1_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_9_1_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(insanedemoncolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_10_btn2_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_10_1_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_10_1_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(extremedemoncolor);
			};


			/*OTHER DIFFICULTIES*/


			if (isSpriteFrameName(difficulty, "difficulty_auto_btn_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_-1_0_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_-1_0_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(autocolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_00_btn_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_0_0_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_0_0_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(nacolor);
			};
		};

	return true;

	}
};



#include <Geode/modify/LevelListLayer.hpp>
class $modify(ColoredNameLevelListLayer, LevelListLayer) { 
	bool init(GJLevelList* list) {

		if (!LevelListLayer::init(list)) {
			return false;
		}

		/*before we start, lets check if this feature is enabled. if it isn't, we'll stop this from running.*/
		bool enabled = Mod::get()->getSettingValue<bool>("Change Title of Lists");

		if (enabled) {

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

			/*get the nodes in the list info layer*/

			auto title = this->getChildByID("title-label");
			auto difficulty = this->getChildByID("difficulty-sprite");

			/*less crashes*/
			if (!title || !difficulty) {
				return true;
			};

			/*now onto editing the list info layer*/
			/*NORMAL DIFFICULTIES (these are different because they have no text under them)*/


			if (isSpriteFrameName(difficulty, "diffIcon_05_btn_001.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(insanecolor);
			};
			if (isSpriteFrameName(difficulty, "diffIcon_04_btn_001.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(hardercolor);
			};
			if (isSpriteFrameName(difficulty, "diffIcon_03_btn_001.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(hardcolor);
			};
			if (isSpriteFrameName(difficulty, "diffIcon_02_btn_001.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(normalcolor);
			};
			if (isSpriteFrameName(difficulty, "diffIcon_01_btn_001.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(easycolor);
			};


			/*DEMON DIFFICULTIES (these are different because they have no text under them)*/


			if (isSpriteFrameName(difficulty, "diffIcon_07_btn_001.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(easydemoncolor);
			};
			if (isSpriteFrameName(difficulty, "diffIcon_08_btn_001.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(mediumdemoncolor);
			};
			if (isSpriteFrameName(difficulty, "diffIcon_06_btn_001.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(harddemoncolor);
			};
			if (isSpriteFrameName(difficulty, "diffIcon_09_btn_001.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(insanedemoncolor);
			};
			if (isSpriteFrameName(difficulty, "diffIcon_10_btn_001.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(extremedemoncolor);
			};


			/*OTHER DIFFICULTIES (these are different because they have no text under them)*/


			if (isSpriteFrameName(difficulty, "diffIcon_auto_btn_001.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(autocolor);
			};
			if (isSpriteFrameName(difficulty, "diffIcon_00_btn_001.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(nacolor);
			};
		};

	return true;

	}
};


/*Edit level names in the levelcell*/

#include <Geode/modify/LevelCell.hpp>
class $modify(MyLevelCell, LevelCell) {
	static void onModify(auto & self) {
		(void) self.setHookPriority("LevelCell::loadFromLevel", 1);
	}
		
	static void editLevelCell(CCLayer* mainLayer) {

		/*before we start, lets check if this feature is enabled. if it isn't, we'll stop this from running.*/
		bool enabled = Mod::get()->getSettingValue<bool>("Change Title of LevelCells");

		if (enabled) {
		
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

			/*get the nodes in the level cell*/

			auto title = mainLayer->getChildByIDRecursive("level-name");
			auto difficulty = mainLayer->getChildByIDRecursive("difficulty-sprite");

			/*less crashes*/
			if (!title || !difficulty) {
				return;
			};

			/*now onto editing the level cell*/
			/*NORMAL DIFFICULTIES*/

			if (isSpriteFrameName(difficulty, "difficulty_05_btn_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_5_0_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_5_0_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(insanecolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_04_btn_001.png")|| /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_4_0_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_4_0_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(hardercolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_03_btn_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_3_0_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_3_0_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(hardcolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_02_btn_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_2_0_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_2_0_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(normalcolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_01_btn_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_1_0_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_1_0_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(easycolor);
			};


			/*DEMON DIFFICULTIES (these are slightly different from the levelinfo ones because they don't use the full demon name, instead they just say "demon")*/


			if (isSpriteFrameName(difficulty, "difficulty_07_btn_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_7_0_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_7_0_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(easydemoncolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_08_btn_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_8_0_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_8_0_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(mediumdemoncolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_06_btn_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_6_0_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_6_0_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(harddemoncolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_09_btn_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_9_0_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_9_0_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(insanedemoncolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_10_btn_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_10_0_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_10_0_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(extremedemoncolor);
			};


			/*OTHER DIFFICULTIES*/


			if (isSpriteFrameName(difficulty, "difficulty_auto_btn_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_-1_0_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_-1_0_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(autocolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_00_btn_001.png") || /*godlike faces mod*/ isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_0_0_3_god.png") || isSpriteFrameName(difficulty, "adyagd.godlikefaces/difficulty_0_0_4_god.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(nacolor);
			};
		};
	};

	/*run*/

	void loadFromLevel(GJGameLevel* level) {
		LevelCell::loadFromLevel(level);
		const auto mainLayer = this->m_mainLayer;
		if (!mainLayer || !m_level) {
			return;
		};
		editLevelCell(mainLayer);
	}
};

/*Edit level names in the levellistcell*/

#include <Geode/modify/LevelListCell.hpp>
class $modify(MyLevelListCell, LevelListCell) {
	static void onModify(auto & self) {
		(void) self.setHookPriority("LevelListCell::loadFromList", 1);
		}

	static void editListLevelCell(CCLayer* mainLayer) {

		/*before we start, lets check if this feature is enabled. if it isn't, we'll stop this from running.*/
		bool enabled = Mod::get()->getSettingValue<bool>("Change Title of List LevelCells");

		if (enabled) {

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

			/*get the nodes in the list cell*/

			auto title = mainLayer->getChildByID("list-name-label");
			auto difficulty = mainLayer->getChildByIDRecursive("difficulty-sprite");

			/*less crashes*/
			if (!title || !difficulty) {
				return;
			};

			/*now onto editing the list cell*/
			/*NORMAL DIFFICULTIES*/
			/*there aren't any mythic/legendary lists so far so i'm not adding godlike faces support for this*/

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


			/*DEMON DIFFICULTIES (these are slightly different from the levelinfo ones because they don't use the full demon name, instead they just say "demon")*/


			if (isSpriteFrameName(difficulty, "difficulty_07_btn_001.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(easydemoncolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_08_btn_001.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(mediumdemoncolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_06_btn_001.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(harddemoncolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_09_btn_001.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(insanedemoncolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_10_btn_001.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(extremedemoncolor);
			};


			/*OTHER DIFFICULTIES*/


			if (isSpriteFrameName(difficulty, "difficulty_auto_btn_001.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(autocolor);
			};
			if (isSpriteFrameName(difficulty, "difficulty_00_btn_001.png")) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(nacolor);
			};
		};	
	};

	/*run*/

	void loadFromList(GJLevelList* list) {
		LevelListCell::loadFromList(list);
		const auto mainLayer = this->m_mainLayer;
		if (!mainLayer || !m_levelList) {
			return;
		};
		 editListLevelCell(mainLayer);
	};

};

/*Edit level names in InfoLayer*/

#include <Geode/binding/GJGameLevel.hpp>
#include <Geode/modify/InfoLayer.hpp>
class $modify(ColoredNameInfoLayer, InfoLayer) {
	bool init(GJGameLevel *level, GJUserScore *score, GJLevelList *list) {
		if (!InfoLayer::init(level, score, list)) {
			return false;
		}

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

		/*BELOW EDITS THE INFOLAYER FOR LEVELS*/
		/*before we start, lets check if this feature is enabled and is a level. if it isn't, we'll stop this from running.*/
		bool enabled = Mod::get()->getSettingValue<bool>("Change Title of InfoLayer");

		if (enabled && m_level) {

			/*get the nodes in the info layer*/

			auto title = this->getChildByIDRecursive("title-label");

			/*less crashes*/
			if (!title) {
				return true;
			};

			/*get the difficulty*/
			int difficulty = (m_level->m_ratingsSum / 10); 
			int demondiff = m_level->m_demonDifficulty;
			/*now onto editing the info layer*/

			if (level->m_ratingsSum != 0) {
				/*NORMAL DIFFICULTIES*/
				if (difficulty == 1) {
					typeinfo_cast<CCRGBAProtocol*>(title)->setColor(easycolor);
				};
				if (difficulty == 2) {
					typeinfo_cast<CCRGBAProtocol*>(title)->setColor(normalcolor);
				};
				if (difficulty == 3) {
					typeinfo_cast<CCRGBAProtocol*>(title)->setColor(hardcolor);
				};
				if (difficulty == 4) {
					typeinfo_cast<CCRGBAProtocol*>(title)->setColor(hardercolor);
				};
				if (difficulty == 5) {
					typeinfo_cast<CCRGBAProtocol*>(title)->setColor(insanecolor);
				};
				if (difficulty == 6) {
					typeinfo_cast<CCRGBAProtocol*>(title)->setColor(harddemoncolor);
				};
			} else {
				/*no rating = n/a*/
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(nacolor);
			};
			if (m_level->m_demon > 0) {
				/*DEMON DIFFICULTIES*/
				/*default to hard demon*/ typeinfo_cast<CCRGBAProtocol*>(title)->setColor(harddemoncolor);
            		if (demondiff == 3) {
						typeinfo_cast<CCRGBAProtocol*>(title)->setColor(easydemoncolor);
					};
					if (demondiff == 4) {
						typeinfo_cast<CCRGBAProtocol*>(title)->setColor(mediumdemoncolor);
					};
					if (demondiff == 5) {
						typeinfo_cast<CCRGBAProtocol*>(title)->setColor(insanedemoncolor);
					};
					if (demondiff == 6) {
						typeinfo_cast<CCRGBAProtocol*>(title)->setColor(extremedemoncolor);
					};
        		};
			if (m_level->m_autoLevel) {
				/*auto*/
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(autocolor);
			};
		};


		/*BELOW EDITS THE INFOLAYER FOR LISTS*/
		/*before we start, lets check if this feature is enabled and is a list. if it isn't, we'll stop this from running.*/
		if (enabled && m_levelList) {

			/*get the nodes in the info layer*/

			auto title = this->getChildByIDRecursive("title-label");
			int difficulty = m_levelList->m_difficulty;

			/*less crashes*/
			if (!title) {
				return true;
			};

			/*now onto editing the info layer*/

			/*DEMON DIFFICULTIES*/

			if (difficulty > 5) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(easydemoncolor);
			};
			if (difficulty > 6) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(mediumdemoncolor);
			};
			if (difficulty > 7) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(harddemoncolor);
			};
			if (difficulty > 8) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(insanedemoncolor);
			};
			if (difficulty > 9) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(extremedemoncolor);
			};

			/*NORMAL DIFFICULTIES*/

			if (difficulty < 6) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(insanecolor);
			};
			if (difficulty < 5) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(hardercolor);
			};
			if (difficulty < 4) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(hardcolor);
			};
			if (difficulty < 3) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(normalcolor);
			};
			if (difficulty < 2) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(easycolor);
			};


			/*OTHER DIFFICULTIES*/

			if (difficulty < 1) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(autocolor);
			};
			if (difficulty < 0) {
				typeinfo_cast<CCRGBAProtocol*>(title)->setColor(nacolor);
			};
		};	
	return true;
	};
};
