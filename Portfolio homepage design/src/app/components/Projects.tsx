import { ExternalLink, Github } from "lucide-react";

const projects = [
  {
    title: "Infrastructure Réseau Pour Une Petite Entreprise",
    description: "Conception et mise en place d'une infrastructure réseau complète avec segmentation VLAN, routage inter-VLAN et sécurisation par ACL,DMZ.",
    tags: ["Cisco", "VLAN", "Routage", "Sécurité"],
    github: "#",
    demo: "#"
  },
  {
    title: "Concours Je Filme Ma Formation",
    description: "Réalisation d'un court métrage pour représenter la formation du BUT Réseaux et Télécommunication classement (3e).",
    tags: ["Vidéo", "Communication", "Créativité", "Teamwork"],
    github: "#",
    demo: "#"
  },
];

export function Projects() {
  return (
    <section id="projets" className="py-20 px-6 bg-muted/30">
      <div className="max-w-6xl mx-auto">
        <div className="text-center mb-16">
          <h2 className="text-4xl mb-4">Projets</h2>
          <p className="text-muted-foreground text-lg">
            Quelques réalisations académiques et personnelles
          </p>
        </div>

        <div className="flex flex-wrap justify-center gap-8 max-w-4xl mx-auto">
          {projects.map((project) => (
            <div
              key={project.title}
              className="bg-card border border-border rounded-xl p-6 hover:shadow-lg transition-shadow flex flex-col w-full md:w-[calc(50%-1rem)]"
            >
              <h3 className="text-xl mb-3">{project.title}</h3>
              <p className="text-muted-foreground mb-4 flex-grow">
                {project.description}
              </p>

              <div className="flex flex-wrap gap-2 mb-4">
                {project.tags.map((tag) => (
                  <span
                    key={tag}
                    className="px-3 py-1 bg-primary/10 text-primary rounded-full text-sm"
                  >
                    {tag}
                  </span>
                ))}
              </div>

              <div className="flex gap-3 pt-4 border-t border-border">
                <a
                  href={project.github}
                  className="flex items-center gap-2 text-sm text-muted-foreground hover:text-foreground transition-colors"
                >
                  <Github className="w-4 h-4" />
                  Code
                </a>
                <a
                  href={project.demo}
                  className="flex items-center gap-2 text-sm text-muted-foreground hover:text-foreground transition-colors"
                >
                  <ExternalLink className="w-4 h-4" />
                  Démo
                </a>
              </div>
            </div>
          ))}
        </div>
      </div>
    </section>
  );
}
