#pragma once

class cloneable {
	public:
	virtual cloneable* clone() const = 0;
	virtual ~cloneable() = default;
};