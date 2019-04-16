#ifndef UIMANAGER_HXX_
#define UIMANAGER_HXX_

#include <vector>

#include "ui/widgets/button.hxx"
#include "ui/widgets/frame.hxx"
#include "ui/widgets/text.hxx"
#include "ui/widgets/textField.hxx"
#include "ui/widgets/tooltip.hxx"
#include "ui/widgets/checkbox.hxx"
#include "ui/widgets/combobox.hxx"
#include "ui/basics/uiElement.hxx"
#include "ui/basics/buttonGroup.hxx"
#include "ui/basics/Layout.hxx"

#include <SDL.h>

/**
 * @brief Struct that hold UiElements belonging to a layoutgroup and its corresponding LayoutData
 * 
 */
struct LayoutGroup
{
  std::vector<UiElement *> uiElements; /// contains pointer to all uiElements belonging to this group
  LayoutData layout;                   /// layout information @see LayoutData
};

/**
 * @brief Draws the UI to the screen
 * Parses UiLayout.json file and instantiates UI widgets accordingly. Also takes care of layouting
 */
class UIManager
{
public:
  /// Retrieves instance of Singleton class UI Manager
  static UIManager &instance()
  {
    static UIManager uiManager;
    return uiManager;
  }
  /**
   * @brief Parses the UiLayout.json files and creates UI Elements
   * 
   */

  void init();
  /**
 * @brief Fill UI Widgets whose ID start with a $ with data
 * Used for filling widgets with data, like BuildMenu Position combobox, Screen Resolution ComboBox and so on
 */
  void initializeDollarVariables();

  /**
  * @brief Renders all UI Widgets
  * 
  */
  void drawUI() const;

  /**
 * @brief Callback function for toggling the visibility of an UiGroup 
 * Callback function for Ui Widgets with the ActionID "ToggleVisiblityOfGroup".
 * The ActionParamter is used for toggling elements from m_uiGroups with the same ID
 * 
 * @param groupID The groupID that should be toggled
 * @param sender The element who called the function
 */
  void toggleGroupVisibility(const std::string &groupID, UiElement *sender = nullptr);

  /**
 * @brief Toggle Visibility of Debug Menu
 * 
 */
  void toggleDebugMenu() { m_showDebugMenu = !m_showDebugMenu; };

  /**
 * @brief Helper function to update the FPS Counter
 * 
 * @param fps 
 */
  void setFPSCounterText(const std::string &fps);

  /**
 * @brief CallbackFunction that sets the Build Menu Position 
 * Used as callback function for the ComboBox that holds the Build Menu position
 * @param sender ComboBox that called the function
 */
  void setBuildMenuPosition(UiElement *sender);

  /**
 * @brief Get all Ui Element objects
 * Returns a container that holds ALL UiElements, even those in buttongroups. 
 * @note Does not return ButtonGroups, only basic widgets
 * @return const std::vector<std::unique_ptr<UiElement>>& 
 */
  const std::vector<std::unique_ptr<UiElement>> &getAllUiElements() const { return m_uiElements; };

  /**
 * @brief Get all Ui Elements For Event Handling 
 * Returns Widgets that are not in ButtonGroups and ButtonGroups. 
 * @note The ButtonGroup container takes care of handling events in it's container, so those widgets are excluded
 * @return const std::vector<UiElement *>& 
 */
  const std::vector<UiElement *> &getAllUiElementsForEventHandling() const { return m_uiElementsForEventHandling; };

  /**
 * @brief Get the UiElements Of aroup 
 * get Elements that are in UiGroup (m_uiGroups)
 * @param groupID ID of the group whose elements should be returned
 * @return const std::vector<UiElement *>* 
 */
  const std::vector<UiElement *> *getUiElementsOfGroup(const std::string &groupID) const;

  /**
 * @brief Get the m_uiGroups object
 * Returns the container, that holds all UiElements sorted by their UI Group
 * @return std::unordered_map<std::string, std::vector<UiElement *>>& 
 */
  std::unordered_map<std::string, std::vector<UiElement *>> &getAllUiGroups() { return m_uiGroups; }

  /**
   * @brief Get the Layoutgroup container
   * Returns the container, that holds LayoutGroups
   * @return std::unordered_map<std::string, LayoutGroup>& 
   */
  std::unordered_map<std::string, LayoutGroup> &getAllLayoutGroups() { return m_layoutGroups; }

  /**
 * @brief Get the Ui Element By ID
 * Finds and returns an UiElement by its elementID parameter
 * @param UiElement ID of the element that should be returned.
 * @return UiElement* 
 */
  UiElement *getUiElementByID(const std::string &ID) const;

  void startTooltip(SDL_Event &event, const std::string &tooltipText);
  void stopTooltip() const;

  void changeResolution(UiElement *sender);

private:
  UIManager() = default;
  ~UIManager() = default;

  // this container holds all UiElements and is the owner.
  std::vector<std::unique_ptr<UiElement>> m_uiElements;

  // stores Buttongroups and UiElements that are not in a group
  std::vector<UiElement *> m_uiElementsForEventHandling;

  // map holding all ui elements, accessible via the group ID
  std::unordered_map<std::string, std::vector<UiElement *>> m_uiGroups;

  // map holding layput groups, accessible via the layoutgroup ID
  std::unordered_map<std::string, LayoutGroup> m_layoutGroups;

  // Holding all buttongroups
  std::unordered_map<std::string, ButtonGroup *> m_buttonGroups;

  std::unique_ptr<Tooltip> m_tooltip = std::make_unique<Tooltip>();

  // Text element for the FPS Counter (debug menu)
  std::unique_ptr<Text> m_fpsCounter = std::make_unique<Text>(SDL_Rect{40, 20, 0, 0});

  void setCallbackFunctions();

  void createBuildMenu();
  void setBuildMenuLayout();

  bool m_showDebugMenu = false;

  void addToLayoutGroup(const std::string &groupName, UiElement *widget);
};

#endif
