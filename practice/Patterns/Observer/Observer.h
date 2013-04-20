#ifndef OBSERVER_H
#define OBSERVER_H
#include <vector>
#include "Subject.h"
class Subject;

class Observer {
	public:
		Observer() {}
		virtual ~Observer() {}
		virtual void Update(Subject* sub) = 0;
		virtual std::vector<int> GetContent() = 0;
		virtual void Delptr() = 0;
};

class View : public Observer {
	public:
		View() {}
		View(Subject* sub);
		virtual ~View();
		virtual void Update(Subject* sub);
		virtual std::vector<int> GetContent();
		virtual void Delptr();
	private:
		Subject* m_subject;
		std::vector<int> m_data;
};

#endif
