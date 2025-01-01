import Experience from "./Classes/Experience.ts";
import Ball from "./Ball.ts";
import "../Utils/Utils.ts"
import { colors, randomColor, randomIntFromRange } from "../Utils/Utils.ts";

export const A_Gravity: number = 1;
export const A_Friction: number = 0.1;

export class World {
    private Experience: Experience;
    //private ball: Ball;
    private balls: Ball[] = [];

    public constructor() {
        this.Experience = new Experience();
        //this.ball = new Ball(this.Experience.canvas.width / 2, this.Experience.canvas.height / 2, 30, 'red', 2, 1);
        for (let i = 0; i < 300; i++) {
            let randomSize = randomIntFromRange(30, 10);
            this.balls.push(
                new Ball(randomIntFromRange(this.Experience.canvas.width - randomSize, randomSize),
                    randomIntFromRange(this.Experience.canvas.height - randomSize, randomSize),
                    randomSize,
                    randomColor(colors),
                    randomIntFromRange(1, 4),
                    randomIntFromRange(-1, 2)));
        }
        //console.log(this.balls);
    }

    public update() {
        this.Experience.context?.clearRect(0, 0, this.Experience.canvas.width, this.Experience.canvas.height);
        //this.ball.update();
        this.balls.forEach((ball) => {
            ball.update();
        })
    }

    public draw() {
        // this.ball.draw();
        this.balls.forEach((ball) => {
            ball.draw();
        })
    }

    public resize() {
        // this.ball = new Ball(this.Experience.canvas.width / 2, this.Experience.canvas.height / 2, 30, 'red', 2, 1);
        this.balls = [];
        for (let i = 0; i < 300; i++) {
            let randomSize = randomIntFromRange(30, 10);
            this.balls.push(
                new Ball(randomIntFromRange(this.Experience.canvas.width - randomSize, randomSize),
                    randomIntFromRange(this.Experience.canvas.height - randomSize, randomSize),
                    randomSize,
                    randomColor(colors),
                    randomIntFromRange(1, 4),
                    randomIntFromRange(-1, 2)));
        }
    }
}