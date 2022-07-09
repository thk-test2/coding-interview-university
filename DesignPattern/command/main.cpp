#include <iostream>
#include <vector>

using namespace std;

class Robot {
public:
	enum class Direction { Left, Right };

	void moveForward(int space) { cout << space << " 칸 전진" << "\n"; }
	void turn(Direction _direction) {
		if (_direction == Direction::Left)
			cout << "왼쪽으로 방향 전환" << "\n";
		else
			cout << "오른쪽으로 방향 전환" << "\n";
	}
	void pickup() { cout << "앞의 물건 집어들기" << "\n"; }
};

class Command {
public:
	Robot* robot;
	void setRobot(Robot* _robot) { robot = _robot; }
	virtual void execute() = 0;
};

class MoveForwardCommand : public Command {
public:
	int space;
	MoveForwardCommand(int _space) { space = _space; }
	void execute() { robot->moveForward(space); }
};

class TurnCommand : public Command {
public:
	Robot::Direction direction;
	TurnCommand(Robot::Direction _direction) { direction = _direction; }
	void execute() { robot->turn(direction); }
};

class PickupCommand : public Command {
public:
	void execute() { robot->pickup(); }
};

class Order {
public:
	virtual void run(Robot* robot) = 0;
};

class MoveBackOrder : public Order {
public:
	int block;
	MoveBackOrder(int _block) : block(_block) { }
	void run(Robot* robot) override{
		robot->turn(Robot::Direction::Left);
		robot->turn(Robot::Direction::Left);
		robot->moveForward(block);
	}
};

class CommandOrderAdapter : public Command {
private:
	Order* order;
public:
	CommandOrderAdapter(Order* _order) :order(_order) {}
	void execute() { order->run(robot); }
};

class RobotKit {
private:
	Robot* robot = new Robot();
	vector<Command*> commands;
public:
	void addCommand(Command* command) { commands.push_back(command); }
	void start() {
		for (auto& command : commands) {
			command->setRobot(robot);
			command->execute();
		}
	}
};

int main() {
	RobotKit rk;
	rk.addCommand(new MoveForwardCommand(5));
	rk.addCommand(new MoveForwardCommand(3));
	rk.addCommand(new MoveForwardCommand(2));
	rk.addCommand(new TurnCommand(Robot::Direction::Left));
	rk.addCommand(new PickupCommand());

	rk.addCommand(new CommandOrderAdapter(new MoveBackOrder(7)));
	rk.start();

	return 0;
}