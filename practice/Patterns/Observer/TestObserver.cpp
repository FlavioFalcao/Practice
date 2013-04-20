#include "Subject.h"
#include "Observer.h"
#define N 5

int main() {
	int a[N] = {12,53,54,2,8};
	std::vector<int> vec(a,a+N);
	for (int i = 0; i < N; i++) {
		printf("vec[%d] = %d\n",i,vec[i]);
	}

	Data* data = new Data;
	Observer* ob1 = new View(data);
	data->SetContent(vec);
	data->Notify();

	std::vector<int> v1;
	v1 = ob1->GetContent();
	for (int i = 0; i < N; i++) {
		printf("ob1 is %d\n",v1[i]);
	}

	delete data; data = NULL;
	delete ob1; ob1 = NULL;
	return 0;
}
