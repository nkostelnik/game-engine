/*!
	@file
	@author		Albert Semenov
	@date		01/2008
	@module
*/
#ifndef __MYGUI_TAB_ITEM_FACTORY_H__
#define __MYGUI_TAB_ITEM_FACTORY_H__

#include "MyGUI_Prerequest.h"
#include "MyGUI_IWidgetFactory.h"
#include "MyGUI_TabItem.h"

namespace MyGUI
{
	namespace factory
	{

		class _MyGUIExport TabItemFactory : public BaseWidgetFactory<TabItem>
		{
		public:
			TabItemFactory();
			~TabItemFactory();

		private:
			// методы для парсинга
			void TabItem_ButtonWidth(WidgetPtr _widget, const std::string &_key, const std::string &_value);
			void TabItem_Select(WidgetPtr _widget, const std::string &_key, const std::string &_value);

		};

		// OBSOLETE
		class _MyGUIExport SheetFactory : public IWidgetFactory
		{
		public:
			SheetFactory();
			const std::string & getTypeName()
			{
				static std::string type = "Sheet";
				return type;
			}
			WidgetPtr createWidget(const std::string& _skin, const IntCoord& _coord, Align _align, ICroppedRectangle * _parent, IWidgetCreator * _creator, const std::string& _name)
			{
				MYGUI_LOG(Warning, "Type 'Sheet' is obsolette, use 'TabItem'");
				return new TabItem(_coord, _align, SkinManager::getInstance().getSkin(_skin), _parent, _creator, _name);
			}
		};


	} // namespace factory
} // namespace MyGUI

#endif // __MYGUI_TAB_ITEM_FACTORY_H__