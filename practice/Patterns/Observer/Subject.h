#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <list>
#include "Observer.h"
class Observer;

class Subject {
	public:
		Subject() {}
		virtual ~Subject() {}
		virtual void Attach(Observer* obv) = 0;
		virtual void Detach(Observer* obv) = 0;
		virtual void Notify() = 0;
		virtual void SetContent(std::vector<int> &content) = 0;
		virtual std::vector<int> GetContent() = 0;
};

class Data : public Subject {
	public:
		Data() {}
		virtual ~Data();
		virtual void Attach(Observer* obv);
		virtual void Detach(Observer* obv);
		virtual void Notify();
		virtual void SetContent(std::vector<int> &content);
		virtual std::vector<int> GetContent();
	private:
		std::list<Observer*> m_ob_list;
		std::vector<int> m_data;
};

#endif
