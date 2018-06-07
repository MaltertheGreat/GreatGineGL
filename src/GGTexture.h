#pragma once

#include <string>

class GGTexture
{
public:
	GGTexture(std::string file_name);

public:
	void Render();

private:
	unsigned m_id;
};
