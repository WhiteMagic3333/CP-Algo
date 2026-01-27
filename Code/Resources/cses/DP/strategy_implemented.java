class Duck {
    public FlyBehaviour fb;
    public QuackBehaviour qb;

    public void quack() {
        qb.quack();
    }

    public void fly() {
        fb.fly();
    }

    protected setFlyBehaviour (FlyBehaviour fb) {
        this.fb = fb;
    }

    protected setQuackBehaviour (QuackBehaviour qb) {
        this.qb = qb;
    }

    public void display() { //normal white duck

    }
}

class AsianDuck extends Duck {
    public void display () { // looks like asian duck

    }
}

class SibereanDuck extends Duck {

    public void display () { // looks like siberean duck

    }
}

class RubberDuck extends Duck {

    void RubberDuck() {
        setFlyBehaviour(new NoFly());
        setQuackBehaviour(new Mute());
    }

    public void display () { // looks like rubber duck

    }
}

class FattyDuck extends Duck {
    //cannot fly
    void FattyDuck() {
        setFlyBehaviour(new NoFly());
    }
}