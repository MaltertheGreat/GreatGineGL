#pragma once

#include <string>

class GGTexture
{
public:
	GGTexture(std::string file_name);

public:
	unsigned GetID() const;

private:
	unsigned m_id;
};
