#ifndef RESOURCE_H
#define RESOURCE_H
#include "ResourceType.h"
#include <string>
#include <iostream>

using namespace std;

namespace SoftUni
{
	class Resource
	{
		int id;
		ResourceType oResourceType;
		string link;

	public:
		ResourceType getType() const
		{
			return oResourceType;
		}

		int getId() const
		{
			return id;
		}

		string getLink() const
		{
			return link;
		}

		bool operator< (const Resource other) const
		{
			return this->id < other.id;
		}

		friend istream& operator >> (istream& iStr, Resource& res);
	};

	istream& operator>> (istream& iStr, ResourceType& rt)
	{
		string resType;
		iStr >> resType;

		if (resType == "Presentation")
			rt = PRESENTATION;
		else if (resType == "Demo")
			rt = DEMO;
		else
			rt = VIDEO;

		return iStr;
	}

	istream& operator>> (istream& iStr, Resource& res) 
	{
		iStr >> res.id >> res.oResourceType >> res.link;

		return iStr;
	}

	ostream& operator<< (ostream& oStr, const Resource& res)
	{
		return oStr << " " << res.getId() << " " << res.getType() << " " << res.getLink();
	}
}

#endif // !RESOURCE_H
