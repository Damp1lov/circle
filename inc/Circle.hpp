#pragma once
#include <SFML/Graphics.hpp>


namespace mt
{
	class Circle
	{
		float m_r;
		float m_x, m_y;
		float m_v;
		float m_alpha;
		sf::CircleShape m_shape;

	public:
		Circle() = default;

		Circle(float x, float y, float r, float v, float alpha)
		{
			Setup(x,y,r, v, alpha);
		}

		void Setup(float x, float y, float r, float v, float alpha)
		{
			m_x = x;
			m_y = y;
			m_r = r;
			m_v = v;
			m_alpha = alpha;
			m_shape.setOrigin(m_r, m_r);
			m_shape.setRadius(m_r);
			m_shape.setPosition(m_x, m_y);
			m_shape.setFillColor(sf::Color::Color(255, 255, 0, 255));
		}

		
		sf::CircleShape Get()
		{
			return m_shape;
		}

		float X() { return m_x; }
		float Y() { return m_y; }
		float R() { return m_r; }
		float Alpha() { return m_alpha; }
		void Alpha(float alpha)
		{
			m_alpha = alpha;
		}

		void Move(float dt)
		{
			float vx = m_v * cos(m_alpha);
			float vy = m_v * sin(m_alpha);

			m_x += vx*dt;
			m_y += vy * dt;
			m_shape.setPosition(m_x, m_y);
		}
	};
}