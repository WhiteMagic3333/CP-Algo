class Duck {
    public void quack() {

    }

    public void fly() {

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
    public void fly () {
        //cannot fly
    }

    public void quack () {
        //mute cannot quack
    }

    public void display () { // looks like rubber duck

    }
}

class MuteDuck extends Duck {
    public void quack () {
        //mute cannot quack
    }
}

class FattyDuck extends Duck {
    //cannot fly
    public void fly () {
        //cannot fly
    }
}



