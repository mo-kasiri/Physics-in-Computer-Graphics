import Experience from "./Classes/Experience.ts";
import Ball from "./Ball.ts";
import "../Utils/Utils.ts"

export const A_Gravity: number = 1;
export const A_Friction: number = 0.1;

export class World {
    private Experience: Experience;
    private ball: Ball;

    public constructor() {
        this.Experience = new Experience();
        this.ball = new Ball(this.Experience.canvas.width / 2, this.Experience.canvas.height / 2, 60, 'red', 2);
    }

    public update() {
        this.Experience.context?.clearRect(0, 0, this.Experience.canvas.width, this.Experience.canvas.height);
        this.ball.update();
    }

    public draw() {
        this.ball.draw();
    }

    public resize() {
        this.ball = new Ball(this.Experience.canvas.width / 2, this.Experience.canvas.height / 2, 60, 'red', 2);
    }
}