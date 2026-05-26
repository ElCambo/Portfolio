import { Github, Linkedin, Mail } from "lucide-react";
import { StarField } from "./StarField";

export function Hero() {
  return (
    <section id="accueil" className="min-h-screen flex items-center justify-center bg-gradient-to-br from-primary via-primary/95 to-primary/80 text-primary-foreground px-6 relative overflow-hidden">
      <StarField />
      <div className="max-w-4xl w-full relative z-10">
        <div className="space-y-8">
          <div className="space-y-4">
            <h1 className="text-5xl md:text-6xl lg:text-7xl">
              Étudiant en BUT R&T
            </h1>
            <p className="text-xl md:text-2xl text-primary-foreground/80">
              Passionné par les réseaux informatiques et le montage vidéo
            </p>
          </div>

          <div className="space-y-3">
            <p className="text-lg text-primary-foreground/70 max-w-2xl">
              Actuellement en 1ère année de BUT Réseaux et Télécommunications, je développe mes compétences
              en administration système, cybersécurité, infrastructures réseau et montage vidéo.
            </p>
          </div>

          <div className="flex gap-4 pt-4">
            <a
              href="https://github.com"
              target="_blank"
              rel="noopener noreferrer"
              className="flex items-center gap-2 px-6 py-3 bg-primary-foreground text-primary rounded-lg hover:opacity-90 transition-opacity"
            >
              <Github className="w-5 h-5" />
              GitHub
            </a>
            <a
              href="https://linkedin.com"
              target="_blank"
              rel="noopener noreferrer"
              className="flex items-center gap-2 px-6 py-3 border-2 border-primary-foreground text-primary-foreground rounded-lg hover:bg-primary-foreground/10 transition-colors"
            >
              <Linkedin className="w-5 h-5" />
              LinkedIn
            </a>
            <a
              href="mailto:contact@exemple.com"
              className="flex items-center gap-2 px-6 py-3 border-2 border-primary-foreground text-primary-foreground rounded-lg hover:bg-primary-foreground/10 transition-colors"
            >
              <Mail className="w-5 h-5" />
              Contact
            </a>
          </div>
        </div>
      </div>
    </section>
  );
}
