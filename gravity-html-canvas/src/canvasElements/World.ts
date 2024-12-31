import Experience from "./Classes/Experience.ts";
import Ball from "./Ball.ts";
import "../Utils/Utils.ts"

export default class World {
    private Experience: Experience;
    private ball: Ball;

    public constructor() {
        this.Experience = new Experience();
        this.ball = new Ball(this.Experience.canvas.width / 2, this.Experience.canvas.height / 2, 60, 'red');
    }

    public update() {
        this.Experience.context?.clearRect(0, 0, this.Experience.canvas.width, this.Experience.canvas.height);
        this.ball.update();
    }

    public draw() {
        this.ball.draw();
    }
}