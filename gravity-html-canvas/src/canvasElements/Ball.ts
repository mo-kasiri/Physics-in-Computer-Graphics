import Experience from "./Classes/Experience.ts";
import "../Utils/Utils.ts"
import { A_Gravity, A_Friction } from "./World.ts";


export default class Ball {
    private Experience: Experience;
    private context: CanvasRenderingContext2D | null;

    ;
    public constructor(
        private x: number,
        private y: number,
        private radius: number,
        private color: string,
        private velocityY: number,
        private velocityX: number) {
        this.Experience = new Experience();
        this.context = this.Experience.context;
    }

    public update() {
        if (this.y + this.radius + this.velocityY > this.Experience.canvas.height) {
            this.velocityY *= (-1 + A_Friction); // Velocity Direction
            this.velocityX *= (A_Friction * 9.85);
        } else {
            this.velocityY += A_Gravity; // Simulating Acceleration
        }

        if (this.x + this.radius + this.velocityX > this.Experience.canvas.width
            ||
            this.x - this.radius + this.velocityX < 0) {
            this.velocityX *= -1;
        }

        this.y += this.velocityY;
        this.x += this.velocityX;
        //console.log(this.velocityX);
        this.draw();
    }

    public draw() {
        this.context!.beginPath();
        this.context!.arc(this.x, this.y, this.radius, 0, Math.PI * 2, false);
        this.context!.fillStyle = this.color;
        this.context!.fill();
        this.context!.stroke();
        this.context!.closePath();
    }
}