#include <Geode/Geode.hpp>
#include <Geode/modify/LevelEditorLayer.hpp>

using namespace geode::prelude;

/* * PhoneOut by Zebtheincredibox
 * A cross-platform layout suite for Windows and Android.
 */

class $modify(PhoneOutEditor, LevelEditorLayer) {
    
    // 1. Initialize the Editor Layer
    bool init(GJGameLevel* level) {
        if (!LevelEditorLayer::init(level)) return false;

        log::info("PhoneOut by Zebtheincredibox successfully loaded!");

        // 2. Create a custom side menu for PhoneOut tools
        auto menu = CCMenu::create();
        menu->setID("phoneout-tools-menu"_spr);
        menu->setPosition({35, 160}); // Left side, above the default buttons
        this->addChild(menu);

        // 3. Add the 'Auto-Align' button
        // Uses the built-in 'align' sprite for a native look
        auto alignSprite = CCSprite::createWithSpriteFrameName("GJ_alignBtn_001.png");
        auto alignBtn = CCMenuItemSpriteExtra::create(
            alignSprite, this, menu_selector(PhoneOutEditor::onPhoneOutAlign)
        );
        alignBtn->setID("align-button"_spr);
        
        menu->addChild(alignBtn);
        menu->updateLayout();

        return true;
    }

    // 4. PhoneOut Feature: Precision Grid Snapping
    void onPhoneOutAlign(CCObject* sender) {
        auto selectedObjects = this->m_uiLayer->getSelection();
        
        if (!selectedObjects || selectedObjects->count() == 0) {
            Notification::create("PhoneOut: Select objects first!", NotificationIcon::Warning)->show();
            return;
        }

        // Snap every selected object to the nearest 30-unit grid (standard GD block size)
        for (auto obj : CCArrayExt<GameObject*>(selectedObjects)) {
            float x = obj->getPositionX();
            float y = obj->getPositionY();

            float snappedX = std::round(x / 30.0f) * 30.0f;
            float snappedY = std::round(y / 30.0f) * 30.0f;

            obj->setPosition({snappedX, snappedY});
        }

        Notification::create("PhoneOut: Grid Snapped", NotificationIcon::Success)->show();
    }
};
