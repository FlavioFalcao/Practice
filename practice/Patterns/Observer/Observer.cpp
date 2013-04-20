#include "Observer.h"

View::View(Subject* sub) {
	m_subject = sub;
	m_subject->Attach(this);
}

View::~View() {
	printf("view deconstructor.\n");
	if (m_subject != NULL) {
		printf("m_subject = %x\n",m_subject);
		m_subject->Detach(this);
		delete m_subject;
		m_subject = NULL;
	}
}

void View::Update(Subject* sub) {
	m_data = sub->GetContent();
}

std::vector<int> View::GetContent() {
	return m_data;
}

void View::Delptr() {
	m_subject = NULL;
}
