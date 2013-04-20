#include "Subject.h"

Data::~Data() {
	std::list<Observer*>::iterator it;
	for (it = m_ob_list.begin(); it != m_ob_list.end(); it++) {
		(*it)->Delptr();
	}
}

void Data::Attach(Observer* obv) {
	m_ob_list.push_back(obv);
}

void Data::Detach(Observer* obv) {
	m_ob_list.remove(obv);
}

void Data::Notify() {
	std::list<Observer*>::iterator it;
	for (it = m_ob_list.begin(); it != m_ob_list.end(); it++) {
		(*it)->Update(this);
	}
}

void Data::SetContent(std::vector<int> &content) {
	m_data = content;
}

std::vector<int> Data::GetContent() {
	return m_data;
}
