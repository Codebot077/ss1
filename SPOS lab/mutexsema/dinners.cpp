#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

const int NUM_PHILOSOPHERS = 5;
std::vector<std::mutex> forks(NUM_PHILOSOPHERS);

void philosopher(int id) {
    int left_fork = id;
    int right_fork = (id + 1) % NUM_PHILOSOPHERS;

    while (true) {
        // Thinking
        std::cout << "Philosopher " << id << " is thinking." << std::endl;

        // Pick up the forks
        forks[left_fork].lock();
        forks[right_fork].lock();

        // Eating
        std::cout << "Philosopher " << id << " is eating." << std::endl;

        // Put down the forks
        forks[right_fork].unlock();
        forks[left_fork].unlock();
    }
}

int main() {
    std::vector<std::thread> philosophers;

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosophers.push_back(std::thread(philosopher, i));
    }

    for (auto& philo : philosophers) {
        philo.join();
    }

    return 0;
}
