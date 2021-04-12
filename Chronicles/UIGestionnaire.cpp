#include "UIGestionnaire.h"

UIGestionnaire::UIGestionnaire()
{
	current = Page::start;
}

UIGestionnaire::~UIGestionnaire()
{
}

void UIGestionnaire::update(sf::RenderWindow* window, sf::Time elapsed)
{
	switch (current) {
	case Page::start:
		start.update(window, elapsed);
		if (start.clickPlay()) {
			survival.reloadSave();
			current = Page::survival;
			start.setPlay(false);
			survival.begin();
		}
		if (start.clickShop()) {
			current = Page::shop;
			start.setShop(false);
			
		}
		break;
	case Page::shop:
		shop.update(window, elapsed);
		if (shop.clickStart()) {
			current = Page::start;
			survival.reloadSave();
			shop.setStart(false);
		}
		break;
	case Page::survival:
		survival.update(window, elapsed);
		if (survival.goMenu()) {
			current = Page::start;
			survival.setGoMenu(false);
			shop.updateGold();
		}
		break;
	default:
		window->close();
	}


}

void UIGestionnaire::render(sf::RenderWindow* window)
{
	switch (current) {
	case Page::start:
		start.render(window);
		break;
	case Page::shop:
		shop.render(window);
		break;
	case Page::survival:
		survival.render(window);
		break;
	default:
		window->close();
	}
}
