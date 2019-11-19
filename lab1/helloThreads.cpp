#include <iostream>
#include <thread>
#include <vector>

static const int num_threads = 10;

void call_from_thread(int tid) {
	std::cout << "Lauched by thread " << tid << std::endl;
}

int main() {

	std::vector<std::thread> vt(num_threads);
	
	int i=0;
	for(std::thread& t: vt){
		t=std::thread(call_from_thread, i++);
	}

	std::cout << "Launched from the main\n";

	for(auto& v : vt){
		v.join();
	}

	return 0;
}
