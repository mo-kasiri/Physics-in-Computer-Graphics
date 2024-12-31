import Experience from "./Classes/Experience.ts";
import "../Utils/Utils.ts"

export default class Ball {
    private Experience: Experience;
    private context: CanvasRenderingContext2D | null;

    private velocityY: number = 10;
    public constructor(
        private x: number,
        private y: number,
        private radius: number,
        private color: string) {
        this.Experience = new Experience();
        this.context = this.Experience.context;
    }

    public update() {
        if (this.y + this.radius > this.Experience.canvas.height || this.y - this.radius < 0) {
            this.velocityY *= -1;
        }


        this.y += this.velocityY;
        this.draw();
    }

    public draw() {
        this.context!.beginPath();
        this.context!.arc(this.x, this.y, this.radius, 0, Math.PI * 2, false);
        this.context!.fillStyle = this.color;
        this.context!.fill();
        this.context!.closePath();
    }
}