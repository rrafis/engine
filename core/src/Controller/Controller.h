#ifndef Core_Controller_h
#define Core_Controller_h

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <thread>
#include <memory>

#include "GraphicsView.h"
#include "InputView.h"
#include "SoundView.h"
#include "GameStateManager.h"
#include "InitialState.h"
#include "ControllerPackage.h"

/**
 * The class that creates, starts, and updates the Model and Views. Simply call the Start method to create all the objects
 * and start them updating.
 */
class Controller : public enable_shared_from_this<Controller>
{
public:
    /**
     * Default constructor that creates a new instance of a Controller.
     */
    Controller();
    
    /**
     * Starts the game. Initializes systems and starts updating them.
     */
    void Start();
    
private:
    // Private constructors to disallow access.
    Controller(Controller const &other);
    Controller operator=(Controller other);
    
    /**
     * The method that udpates all game logic.
     */
    void gameLoop();
    
    /**
     * The method that updates the GraphicsView.
     */
    void viewLoop();
    
    /**
     * How quickly the game logic updates. 1 over the number of updates per second.
     */
    const unsigned int UPDATE_RATE = (int)((1.0 / 60.0) * 1000.0);
    
    /**
     * How quickly the graphics are updated. 1 over the number of frames per second.
     */
    const unsigned int FRAMERATE = (int)((1.0 / 60.0) * 1000.0);

    /**
     * Boolean that represents whether the game should exit or not.
     */
    volatile bool shouldExit;
    
    /**
     * Boolean that represents whether the views have been created or not.
     */
    volatile bool viewsCreated;

    void updateViews(GraphicsView* graphicsView, InputView* inputView, std::shared_ptr<SoundView>* soundView);

    /**
     * Handle all pending SFML window events for the given window.
     * READ SFML DOCUMENTATION ON WINDOW EVENTS BEFORE MODIFYING THIS CODE!!
     *
     * @param window SFML window to process events
     */
    void handleEvents(std::shared_ptr<sf::RenderWindow> window, InputView* view);
};

#endif
