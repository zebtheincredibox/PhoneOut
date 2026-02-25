#include <Geode/Geode.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>

using namespace geode::prelude;

class $modify(PhoneOutLogic, LevelEditorLayer) {
    // 1. Setup the UI when the editor opens
    bool init(GJGameLevel* level) {
        if (!LevelEditorLayer::init(level)) return false;

        auto menu = this->getChildByID("settings-menu");
        
        // Create the PhoneOut Quick-Block button
        auto sprite = CCSprite::createWithSpriteFrameName("GJ_plusBtn_001.png");
        auto btn = CCMenuItemSpriteExtra::create(
            sprite, this, menu_selector(PhoneOutLogic::onQuickBlock)
        );
        btn->setID("quick-block-btn"_spr);

        menu->addChild(btn);
        menu->updateLayout();

        return true;
    }

    // 2. The Logic: Placing a layout block easily
    void onQuickBlock(CCObject* sender) {
        // Get the center of the current editor view
        auto winSize = CCDirector::get()->getWinSize();
        auto screenCenter = winSize / 2;

        // Create a basic layout block (ID 1)
        auto object = this->createObject(1, screenCenter, true);
        
        // Refresh the UI so the user sees the new block
        this->m_uiLayer->updateObjectCount(this->getAllObjects()->count());
        
        Notification::create("PhoneOut: Block Placed!", NotificationIcon::Success)->show();
    }
};
