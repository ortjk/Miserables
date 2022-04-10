#include "Game.h"

void Game::initVariables()
{
	window.create(sf::VideoMode(1280, 720), "Game", sf::Style::Default);

	if (!this->gameFont.loadFromFile("StitchWarriorDemo.ttf"))
	{
		std::cout << "ERROR COULD NOT LOAD GAME FONT\n";
	}

	if (!this->cutsceneFont.loadFromFile("DancingScript-VariableFont_wght.ttf"))
	{
		std::cout << "ERROR COULD NOT LOAD CUTSCENE FONT\n";
	}

	scoreText.setFont(gameFont);
	scoreText.setFillColor(sf::Color(255, 255, 255));
	scoreText.setOutlineThickness(1.f);
	scoreText.setCharacterSize(36);
	scoreText.setPosition(25.f, 25.f);

	timeText.setFont(gameFont);
	timeText.setFillColor(sf::Color(255, 255, 255));
	scoreText.setOutlineThickness(1.f);
	timeText.setCharacterSize(36);
	timeText.setPosition(25.f, 25.f);

	cutsceneText1.setFont(cutsceneFont);
	cutsceneText1.setFillColor(sf::Color(255, 255, 255));
	cutsceneText1.setCharacterSize(36);
	cutsceneText1.setPosition(0.f, 0.f);
	cutsceneText1.setString("Apres j\'ai quitte la bagne, j\'ai voyage a Digne pour commencer mon parole. Quand j\'ai arrive j\'ai\n essayer de trouver un emploi mais rien l\'acceptent a cause de ma passeporte jaune. Pour rester\n chaud j\'ai dormi dehors un eglise, c\'est la ou j\'ai rencontre mon sauveur, monseigneur Myriel.\n Il lui a offert de la nourriture et des logements pour la nuit, mais quand j\'ai eu de la chance\n j\'suis revenu a mes anciennes habitudes. J\'ai vole des bougeoirs pour vendre, mais, les policiers\n m\'arretent et me retournent a l\'eglise devant monsegur . Myriel, mais a ma surprise il dit\n qu\'il a donne ces bougeoirs a moi! Quand les policiers se quittent, monseigneur  Myriel m\'a dit\n qu\'il va acheter mon ame et donne a dieu, pour se payer cette dette j\'ai promis de devenir un\n honnete homme.");

	cutsceneText2.setFont(cutsceneFont);
	cutsceneText2.setFillColor(sf::Color(255, 255, 255));
	cutsceneText2.setCharacterSize(36);
	cutsceneText2.setPosition(0.f, 0.f);
	cutsceneText2.setString("Tu as echoue et Jean Valjean a ete capture");

	cutsceneText3.setFont(cutsceneFont);
	cutsceneText3.setFillColor(sf::Color(255, 255, 255));
	cutsceneText3.setCharacterSize(36);
	cutsceneText3.setPosition(0.f, 0.f);
	cutsceneText3.setString("Finalement je suis libre de javert pour le moment, mais je dois trouver Cosette pour garder\n ma promesse avec fantine.");

	skipText.setFont(cutsceneFont);
	skipText.setFillColor(sf::Color(255, 255, 255));
	skipText.setCharacterSize(36);
	skipText.setPosition(1000.f, 650.f);
	skipText.setString("Passer: Z");
}

Game::Game()
{
	this->state = new State;
	this->initVariables();
}

Game::~Game()
{
	delete this->state;
}

void Game::run()
{
	int x = -2;
	while (this->window.isOpen())
	{
		if (clock.getElapsedTime().asMilliseconds() >= 0.0166667f)
		{
			sf::Event event;
			switch (stage)
			{
				case 0:

					state->playDialogue(INTRO_1);
					state->addEntity(POLICE, 0);

					this->window.clear();
					state->getVisuals(&this->window);
					this->window.display();

					while (this->window.isOpen() && !state->hasAudioFinished() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
					{
						while (this->window.pollEvent(event))
						{
							switch (event.type)
							{
								case sf::Event::Closed:
									this->window.close();
									break;
								default:
									break;
							}
						}
					}
					totalClock.restart();
					state->removeEntity(1);

					stage = 1;
					break;
				case 1:
					scoreText.setString("Francs " + std::to_string(state->getCoinsCollected()));

					while (this->window.pollEvent(event))
					{
						switch (event.type)
						{
							case sf::Event::Closed:
								this->window.close();
								break;
							case sf::Event::KeyPressed:
								switch (event.key.code)
								{
									case sf::Keyboard::Up:
										state->moveEntity(PLAYER, UP);
										break;
									case sf::Keyboard::Down:
										state->moveEntity(PLAYER, DOWN);
										break;
									default:
										break;
								}
								break;
							default:
								break;
						}
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						state->moveEntity(PLAYER, LEFT);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					{
						state->moveEntity(PLAYER, RIGHT);
					}

					state->moveEntity(COIN, LEFT);
					state->moveEntity(OBSTACLE, LEFT);

					//add coin every 2 seconds
					if (lastTimeC - totalClock.getElapsedTime().asSeconds() <= 0)
					{
						lastTimeC += 2.f;

						state->addEntity(COIN, rand() % 3);
					}

					//add obstacle every 1 seconds
					if (lastTimeO - totalClock.getElapsedTime().asSeconds() <= 0)
					{
						lastTimeO += 1.f;

						state->addEntity(OBSTACLE, rand() % 3, rand() % 3);
					}

					//push frames
					this->window.clear();

					state->getVisuals(&this->window);

					this->window.draw(scoreText);

					this->window.display();

					if (state->hasDied())
					{
						state->addEntity(POLICE, 0);
						state->playDialogue(CAUGHT_1);

						this->window.clear();
						state->getVisuals(&this->window);
						this->window.display();

						while (window.isOpen() && stage != 2)
						{
							while (this->window.pollEvent(event))
							{
								switch (event.type)
								{
									case sf::Event::Closed:
										this->window.close();
										break;
									default:
										break;
								}
							}

							if (state->hasAudioFinished())
							{
								stage = 2;
							}
						}
						delete this->state;
						this->state = new State;
						lastTimeO = 0;
					}
					break;

				case 2:
					state->playDialogue(MID_CUTSCENE);
					while (window.isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
					{
						while (this->window.pollEvent(event))
						{
							switch (event.type)
							{
								case sf::Event::Closed:
									this->window.close();
									break;
								default:
									break;
							}
						}

						this->window.clear();

						this->window.draw(this->cutsceneText1);
						this->window.draw(this->skipText);

						this->window.display();
					}
					stage = 3;
					totalClock.restart();
					break;

				case 3:
					state->playDialogue(INTRO_2);
					state->addEntity(POLICE, 0, 1);

					this->window.clear();
					state->getVisuals(&this->window);
					this->window.display();

					while (this->window.isOpen() && !state->hasAudioFinished())
					{
						while (this->window.pollEvent(event))
						{
							switch (event.type)
							{
								case sf::Event::Closed:
									this->window.close();
									break;
								default:
									break;
							}
						}
					}
					totalClock.restart();
					state->removeEntity(1);

					stage = 4;
					break;

				case 4:
					timeText.setString("Temps " + std::to_string(static_cast<int>(totalClock.getElapsedTime().asSeconds())) + "s de 60s");
					while (this->window.pollEvent(event))
					{
						switch (event.type)
						{
							case sf::Event::Closed:
								this->window.close();
								break;
							case sf::Event::KeyPressed:
								switch (event.key.code)
								{
									case sf::Keyboard::Up:
										state->moveEntity(PLAYER, UP);
										break;
									case sf::Keyboard::Down:
										state->moveEntity(PLAYER, DOWN);
										break;
									default:
										break;
								}
								break;
							default:
								break;
						}
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						state->moveEntity(PLAYER, LEFT);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					{
						state->moveEntity(PLAYER, RIGHT);
					}

					state->moveEntity(OBSTACLE, LEFT);

					//add obstacle every 1.2 seconds
					if (lastTimeO - totalClock.getElapsedTime().asSeconds() <= x)
					{
						x = -1.2;
						lastTimeO += 1.2f;

						state->addEntity(OBSTACLE, rand() % 3, rand() % 3);
					}

					state->increasesEntitySpeed(OBSTACLE);

					//push frames
					this->window.clear();

					state->getVisuals(&this->window);

					this->window.draw(timeText);

					this->window.display();

					if (state->hasDied())
					{
						state->addEntity(POLICE, 0, 1);
						state->playDialogue(BAD_ENDING);

						this->window.clear();
						state->getVisuals(&this->window);
						this->window.display();

						while (window.isOpen() && stage != 5)
						{
							while (this->window.pollEvent(event))
							{
								switch (event.type)
								{
									case sf::Event::Closed:
										this->window.close();
										break;
									default:
										break;
								}
							}

							if (state->hasAudioFinished())
							{
								stage = 5;
							}
						}
						delete this->state;
						this->state = new State;
					}

					if (totalClock.getElapsedTime().asSeconds() > 60.f)
					{
						delete this->state;
						this->state = new State;
						stage = 6;
					}

					break;

				case 5:
					skipText.setString("Refaire: Z");
					while (window.isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
					{
						while (this->window.pollEvent(event))
						{
							switch (event.type)
							{
								case sf::Event::Closed:
									this->window.close();
									break;
								default:
									break;
							}
						}

						this->window.clear();

						this->window.draw(this->cutsceneText2);
						this->window.draw(skipText);

						this->window.display();
					}
					stage = 0;
					totalClock.restart();
					break;

				case 6:
					state->playDialogue(GOOD_ENDING);
					skipText.setString("Refaire: Z");
					while (window.isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
					{
						while (this->window.pollEvent(event))
						{
							switch (event.type)
							{
								case sf::Event::Closed:
									this->window.close();
									break;
								default:
									break;
							}
						}

						this->window.clear();

						this->window.draw(this->cutsceneText3);
						this->window.draw(skipText);

						this->window.display();
					}
					stage = 0;
					totalClock.restart();
					break;

				default:
					while (this->window.pollEvent(event))
					{
						switch (event.type)
						{
							case sf::Event::Closed:
								this->window.close();
								break;
							default:
								break;
						}
					}
					break;
			}
			clock.restart();
		}
	}
}