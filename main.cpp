#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

const int WIDTH = 800;
const int HEIGHT = 600;
const int PARTICLE_COUNT = 100000;

struct Particle {
    sf::Vector2f position;
    sf::Vector2f velocity;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Particle Emulator");

    std::vector<Particle> particles(PARTICLE_COUNT);
    std::default_random_engine generator;
    std::uniform_real_distribution<float> distribution(0.0f, 1.0f);

    for (auto &particle : particles) {
        particle.position = sf::Vector2f(distribution(generator) * WIDTH, distribution(generator) * HEIGHT);
        particle.velocity = sf::Vector2f(distribution(generator) * 2.0f - 1.0f, distribution(generator) * 2.0f - 1.0f);
    }

    sf::VertexArray vertices(sf::Points, PARTICLE_COUNT);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (size_t i = 0; i < PARTICLE_COUNT; ++i) {
            particles[i].position += particles[i].velocity;

            if (particles[i].position.x < 0 || particles[i].position.x > WIDTH)
                particles[i].velocity.x *= -1;
            if (particles[i].position.y < 0 || particles[i].position.y > HEIGHT)
                particles[i].velocity.y *= -1;

            vertices[i].position = particles[i].position;
            vertices[i].color = sf::Color::White;
        }

        window.clear();
        window.draw(vertices);
        window.display();
    }

    return 0;
}
