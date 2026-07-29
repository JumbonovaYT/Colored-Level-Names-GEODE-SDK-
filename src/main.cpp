#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/modify/LevelListLayer.hpp>
#include <Geode/modify/LevelListCell.hpp>
#include <Geode/modify/LevelCell.hpp>
#include <Geode/modify/InfoLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/LevelPage.hpp>
using namespace geode::prelude;

static cocos2d::ccColor3B getColorFromModSettings(const geode::ZStringView key) {
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
	if (level->m_autoLevel) return 0;
	GJDifficulty diff = level->m_difficulty;
	if (level->m_ratingsSum != 0) diff = static_cast<GJDifficulty>(level->m_ratingsSum / 10);
	else {
		switch (static_cast<int>(diff)) { 
			case 0: return -1;
			case 6: return 8; // main demon levels
		}
	};

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
		case GJDifficulty::NA: return -1;
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
		getColorFromModSettings("Auto Level Color"),
		getColorFromModSettings("Easy Level Color"),
		getColorFromModSettings("Normal Level Color"),
		getColorFromModSettings("Hard Level Color"),
		getColorFromModSettings("Harder Level Color"),
		getColorFromModSettings("Insane Level Color"),
		getColorFromModSettings("Easy Demon Level Color"),
		getColorFromModSettings("Medium Demon Level Color"),
		getColorFromModSettings("Hard Demon Level Color"),
		getColorFromModSettings("Insane Demon Level Color"),
		getColorFromModSettings("Extreme Demon Level Color")
	};
}


class $modify(LevelInfoLayer) {
	bool init(GJGameLevel* level, bool info) {
		if (!LevelInfoLayer::init(level, info)) return false;
		if (!Mod::get()->getSettingValue<bool>("Change Names of Levels")) return true;

		if (auto title = typeinfo_cast<CCLabelBMFont*>(this->getChildByID("title-label"))) {
			auto diff = getLevelDifficulty(level);
			if (diff == -1) title->setColor(getColorFromModSettings("N/A Level Color"));
			else title->setColor(getColors()[diff]);
		}
		return true;
	}
};

class $modify(LevelListLayer) { 
	bool init(GJLevelList* list) {
		if (!LevelListLayer::init(list)) return false;
		if (!Mod::get()->getSettingValue<bool>("Change Names of Lists") || !m_levelList) return true;

		if (auto title = typeinfo_cast<CCLabelBMFont*>(this->getChildByID("title-label"))) {
			if (m_levelList->m_difficulty == -1) title->setColor(getColorFromModSettings("N/A Level Color"));
			else title->setColor(getColors()[m_levelList->m_difficulty]);
		}
		return true;
	}
};

class $modify(LevelCell) {
	static void onModify(auto & self) {
		(void) self.setHookPriority("LevelCell::loadCustomLevelCell", 1);
	}

	void loadCustomLevelCell() {
		LevelCell::loadCustomLevelCell();
		if (!Mod::get()->getSettingValue<bool>("Change Names of LevelCells")) return;

		if (const auto mainLayer = this->m_mainLayer; auto title = typeinfo_cast<CCLabelBMFont*>(mainLayer->getChildByID("level-name"))) {
			auto diff = getLevelDifficulty(m_level);
			if (diff == -1) title->setColor(getColorFromModSettings("N/A Level Color"));
			else title->setColor(getColors()[diff]);
		}
	}
};

class $modify(LevelListCell) {
	static void onModify(auto & self) {
		(void) self.setHookPriority("LevelListCell::loadFromList", 1);
	}

	void loadFromList(GJLevelList* list) {
		LevelListCell::loadFromList(list);
		if (!Mod::get()->getSettingValue<bool>("Change Names of ListLevelCells")) return;

		if (const auto mainLayer = this->m_mainLayer; auto title = typeinfo_cast<CCLabelBMFont*>(mainLayer->getChildByID("list-name-label"))) {
			if (list->m_difficulty == -1) title->setColor(getColorFromModSettings("N/A Level Color"));
			else title->setColor(getColors()[list->m_difficulty]);
		}
	}
};

class $modify(InfoLayer) {
	bool init(GJGameLevel *level, GJUserScore *score, GJLevelList *list) {
		if (!InfoLayer::init(level, score, list)) return false;
		if (!Mod::get()->getSettingValue<bool>("Change Names of InfoLayers")) return true;
		
		if(auto title = typeinfo_cast<CCLabelBMFont*>(m_mainLayer->getChildByID("title-label"))) {
			if (level) {
				auto diff = getLevelDifficulty(level);
				if (diff == -1) title->setColor(getColorFromModSettings("N/A Level Color"));
				else title->setColor(getColors()[diff]);
			} 
			if (list) {
				if (list->m_difficulty == -1) title->setColor(getColorFromModSettings("N/A Level Color"));
				else title->setColor(getColors()[list->m_difficulty]);
			}
		}
		return true;
	}
};

class $modify(PauseLayer) {
	void customSetup() {
		PauseLayer::customSetup();
		if (!Mod::get()->getSettingValue<bool>("Change Names of PauseLayer")) return;

		if (auto level = PlayLayer::get()->m_level) {
			if (level->m_isEditable) return; // m_levelType is always SearchResult for me so ill just use this
			
			if (auto title = typeinfo_cast<CCLabelBMFont*>(this->getChildByID("level-name"))) {
				int diff = getLevelDifficulty(level);
				if (diff == -1) title->setColor(getColorFromModSettings("N/A Level Color"));
				else title->setColor(getColors()[diff]);
			}
		}
	}
};

class $modify(LevelPage) {
	void updateDynamicPage(GJGameLevel* level) {LevelPage::updateDynamicPage(level);
		if (!Mod::get()->getSettingValue<bool>("Change Names of Main Levels") || !m_nameLabel) return;

		if (level) {
			auto diff = getLevelDifficulty(level);
			if (diff == -1) m_nameLabel->setColor(getColorFromModSettings("N/A Level Color"));
			else m_nameLabel->setColor(getColors()[diff]);
		} 
	}
};