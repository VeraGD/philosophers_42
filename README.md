# philosophers_42

### 1. Project description
This project consists of philosophers eating, sleeping and eating, in that order, without dying.

The problem is that each philosopher has only one fork and needs two to be able to eat. So he has to use his own fork and the fork of another philosopher. 

The philosophers have to take turns to eat, then sleep and finally think until they eat again.

### 2. How to execute the program

- Clone the repository

- Execute the comand make inside the project folder

```ruby
$> make
```

- As arguments you get the number of philosophers, the time they have to die once they have started eating the last time, the time they take to eat, the time they take to sleep, and as an optional parameter, how many meals each philosopher has to eat to finish the simulation:
```ruby
$> ./philo number_of_philosophers  time_to_die  time_to_eat  time_to_sleep  [number_of_times_each_philosopher_must_eat]   

# Example

$> ./philo 5 800 200 200 5
```

### 3. Results obtained
As output the program returns what each philosopher is doing and in what time.

It prints the time since the start of the simulation, which philosopher and what he is doing. He can pick up a fork, pick up another fork, eat, sleep and think. Format:

```ruby
$> ./philo 3 800 200 200 3
0 1 has taken a fork
0 1 has taken a fork
0 3 has taken a fork
0 1 is eating
200 1 is sleeping
200 2 has taken a fork
200 3 has taken a fork
200 3 is eating
400 1 is thinking
400 1 has taken a fork
400 3 is sleeping
400 2 has taken a fork
400 2 is eating
600 2 is sleeping
600 1 has taken a fork
600 1 is eating
600 3 is thinking
600 3 has taken a fork
800 2 is thinking
800 1 is sleeping
800 2 has taken a fork
800 3 has taken a fork
800 3 is eating
1000 1 is thinking
1000 3 is sleeping
1000 2 has taken a fork
1000 2 is eating
1000 1 has taken a fork
1200 2 is sleeping
1200 1 has taken a fork
1200 1 is eating
1200 3 is thinking
1200 3 has taken a fork
1400 2 is thinking
1400 1 is sleeping
1400 3 has taken a fork
1400 3 is eating
1400 2 has taken a fork
1600 1 is thinking
1600 1 has taken a fork
1600 2 has taken a fork
1600 2 is eating
```
