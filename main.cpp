#include <iostream>
#include <random>

#include <SFML/Graphics.hpp>

sf::Vector2f move(double direction, double velocity, double time) {
    double radians = direction * (std::acos(-1) / 180);
    double x = velocity * cos(radians) * (time);
    double y = velocity * sin(radians) * (time);
    return sf::Vector2f(x, y);
}

double applyFriction(double velocity, double time, double friction) {
    double deltaV = friction * time;
    if (velocity - deltaV > 0) {
        velocity -= deltaV;
    }
    else {
        velocity = 0;
    }
    return velocity;
}

class Controller {

public:
    virtual void onEvent(sf::Event& event) = 0;

};

class Component {

public:
    virtual void update() = 0;

public:
    virtual std::vector<std::reference_wrapper<sf::Drawable>> components() = 0;

};

class Agent : public Component, public Controller {

private:
    sf::RectangleShape shape;

private:
    int direction = 0;

private:
    double velocity = 0.0;

public:
    Agent() {
        shape.setSize(sf::Vector2f(10, 10));
        shape.setPosition(sf::Vector2f(500, 300));
    }

public:
    void update() override {
        const float FRICTION = 0.3f;
        const float TIME = 1;

        sf::Vector2f pos = move(direction, velocity, TIME);
        shape.move(pos.y, -pos.x);
        velocity = applyFriction(velocity, TIME, FRICTION);
    }

public:
    std::vector<std::reference_wrapper<sf::Drawable>> components() override {
        std::vector<std::reference_wrapper<sf::Drawable>> vector;
        vector.push_back(shape);

        return vector;
    }

public:
    void onEvent(sf::Event& event) {
        switch (event.type) {
        case sf::Event::KeyPressed:

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                direction = 0;
                velocity = 4;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                direction = 180;
                velocity = 4;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                direction = 270;
                velocity = 4;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                direction = 90;
                velocity = 4;
            }

            break;
        }
    }

};

class Game {

private:
    sf::RenderWindow window;

private:
    Agent agent;

private:
    std::vector<std::reference_wrapper<Component>> components;

public:
    Game(sf::VideoMode mode) {
        window.create(mode, "Agent Simulation");
        components.push_back(agent);
    }

public:
    void render() {
        for (Component& component : components) {
            component.update();

            for (sf::Drawable& drawable : component.components()) {
                window.draw(drawable);
            }
        }
    }

public:
    sf::RenderWindow& getWindow() {
        return window;
    }

public:
    Controller& getController() {
        return agent;
    }

};

int main()
{
    Game game(sf::VideoMode(1000, 600));
    sf::RenderWindow& window(game.getWindow());
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:

                window.close();

                break;
            case sf::Event::KeyPressed:

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    window.close();

                game.getController().onEvent(event);

                break;
            }
        }

        window.clear();

        game.render();

        window.display();
    }

    return 0;
}
