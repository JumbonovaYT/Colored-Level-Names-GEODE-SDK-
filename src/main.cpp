#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/modify/LevelListLayer.hpp>
#include <Geode/modify/LevelListCell.hpp>
#include <Geode/modify/LevelCell.hpp>
using namespace geode::prelude;

static cocos2d::ccColor3B getColorFromModSettings(const std::string_view key) {
	return Mod::get()->getSettingValue<cocos2d::ccColor3B>(key);
}

/*
original code adapted from Eclipse Menu:
https://raw.githubusercontent.com/EclipseMenu/EclipseMenu/main/src/modules/labels/variables.cpp

code re-use + adaptation w/o EPL relicensing is possible per Section 1(b) of EPLv2,
and clarified by EPL's FAQ page:
Question 25: https://www.eclipse.org/legal/epl/faq/#DERIV
Question 27: https://www.eclipse.org/legal/epl/faq/#EXAMPLE

this geode mod/ piece of software serves a significantly different purpose than Eclipse Menu,
and therefore does not qualify as a derivative work from Eclipse Menu.

this function is a helper to be used in combination with the getColors() function
*/

static int getLevelDifficulty(GJGameLevel* level) {
	if (level->m_autoLevel) return -1;

	auto diff = level->m_difficulty;

	if (level->m_ratingsSum != 0) diff = static_cast<GJDifficulty>(level->m_ratingsSum / 10);

	if (level->m_demon > 0) {
		auto demonDiff = level->m_demonDifficulty;
		switch (demonDiff) {
			case 3:
			case 4: return demonDiff + 3;
			case 5:
			case 6: return demonDiff + 4;
			default: return 8;
		}
	}

	switch (diff) {
		case GJDifficulty::Demon: return 8;
		case GJDifficulty::Easy:
		case GJDifficulty::Normal:
		case GJDifficulty::Hard:
		case GJDifficulty::Harder:
		case GJDifficulty::Insane: return static_cast<int>(diff);
		default: return 0;
	}
}

static std::array<cocos2d::ccColor3B, 11> getColors() {
	return std::array<cocos2d::ccColor3B, 11> {
		// m_levelList->m_difficulty
		/*
		auto: 0, easy: 1, normal: 2, hard: 3
		harder: 4, insane: 5
		easy demon: 6, medium demon: 7
		hard demon: 8, insane demon: 9, extreme demon: 10
		*/

		/*starting with auto difficulty*/
		getColorFromModSettings("Auto Level Color"),

		/*now for main difficulties*/
		getColorFromModSettings("Easy Level Color"),
		getColorFromModSettings("Normal Level Color"),
		getColorFromModSettings("Hard Level Color"),
		getColorFromModSettings("Harder Level Color"),
		getColorFromModSettings("Insane Level Color"),

		/*now onto demon difficulties*/

		getColorFromModSettings("Easy Demon Level Color"),
		getColorFromModSettings("Medium Demon Level Color"),
		getColorFromModSettings("Hard Demon Level Color"),
		getColorFromModSettings("Insane Demon Level Color"),
		getColorFromModSettings("Extreme Demon Level Color")
	};
}

/*Edit level names in the level info layer*/

class $modify(ColoredNameLevelInfoLayer, LevelInfoLayer) {
	bool init(GJGameLevel* level, bool info) {

		if (!LevelInfoLayer::init(level, info)) {
			return false;
		}

		if (!Mod::get()->getSettingValue<bool>("Change Title of LevelInfo")) return true;

		/*get the nodes in the level info page*/

		auto title = typeinfo_cast<CCLabelBMFont*>(this->getChildByID("title-label"));

		if (!title) return true;

		auto diff = getLevelDifficulty(level);
		if (diff == -1) title->setColor(getColorFromModSettings("N/A Level Color"));
		else title->setColor(getColors()[diff]);

		return true;
	}
};

class $modify(ColoredNameLevelListLayer, LevelListLayer) { 
	bool init(GJLevelList* list) {

		if (!LevelListLayer::init(list)) {
			return false;
		}

		/*before we start, lets check if this feature is enabled. if it isn't, we'll stop this from running.*/

		if (!Mod::get()->getSettingValue<bool>("Change Title of Lists") || !m_levelList) return true;

		/*get the node in the level info page*/

		auto title = typeinfo_cast<CCLabelBMFont*>(this->getChildByID("title-label"));
		if (!title) return true;

		if (m_levelList->m_difficulty == -1) title->setColor(getColorFromModSettings("N/A Level Color"));
		else title->setColor(getColors()[m_levelList->m_difficulty]);

		return true;

	}
};


class $modify(MyLevelCell, LevelCell) {
	static void onModify(auto & self) {
		(void) self.setHookPriority("LevelCell::loadFromLevel", 1);
	}

	static void editLevelCell(CCLayer* mainLayer, GJGameLevel* level) {
		if (!Mod::get()->getSettingValue<bool>("Change Title of LevelCell")) return;

		/*get the nodes in the level info page*/

		auto title = typeinfo_cast<CCLabelBMFont*>(mainLayer->getChildByIDRecursive("level-name"));

		if (!title) return;

		auto diff = getLevelDifficulty(level);
		if (diff == -1) title->setColor(getColorFromModSettings("N/A Level Color"));
		else title->setColor(getColors()[diff]);

	};

	/*run*/

	void loadCustomLevelCell() {
		LevelCell::loadCustomLevelCell();
		const auto mainLayer = this->m_mainLayer;
		if (!mainLayer || !m_level) return;
		editLevelCell(mainLayer, m_level);
	}
};

class $modify(MyLevelListCell, LevelListCell) {
	static void onModify(auto & self) {
		(void) self.setHookPriority("LevelListCell::loadFromList", 1);
	}

	static void editListLevelCell(CCLayer* mainLayer, GJLevelList* levelList) {
		if (!Mod::get()->getSettingValue<bool>("Change Title of List LevelCells")) return;

		/*get the nodes in the level info page*/

		auto title = typeinfo_cast<CCLabelBMFont*>(mainLayer->getChildByID("list-name-label"));
		if (!title) return;

		if (levelList->m_difficulty == -1) title->setColor(getColorFromModSettings("N/A Level Color"));
		else title->setColor(getColors()[levelList->m_difficulty]);
	}

	/*run*/

	void loadFromList(GJLevelList* list) {
		LevelListCell::loadFromList(list);
		const auto mainLayer = this->m_mainLayer;
		if (!mainLayer || !m_levelList) return;
		editListLevelCell(mainLayer, m_levelList);
	}

};
