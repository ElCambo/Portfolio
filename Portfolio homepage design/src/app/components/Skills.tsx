import { Network, Shield, Server, Radio, Code, Database } from "lucide-react";

const skills = [
  {
    icon: Network,
    title: "Réseaux",
    description: "Configuration et administration de réseaux LAN/WAN, routage, switching, protocoles TCP/IP"
  },
  {
    icon: Shield,
    title: "Cybersécurité",
    description: "Sécurité des systèmes d'information, pare-feu, VPN, détection d'intrusion"
  },
  {
    icon: Server,
    title: "Administration Système",
    description: "Linux, Windows Server, virtualisation, gestion de services réseau"
  },
  {
    icon: Radio,
    title: "Télécommunications",
    description: "Téléphonie IP, réseaux sans fil, transmission de données"
  },
  {
    icon: Code,
    title: "Programmation",
    description: "Python, Bash, automatisation réseau, scripting"
  },
  {
    icon: Database,
    title: "Bases de données",
    description: "SQL, administration de bases de données, sauvegarde et restauration"
  }
];

export function Skills() {
  return (
    <section id="competences" className="py-20 px-6 bg-background">
      <div className="max-w-6xl mx-auto">
        <div className="text-center mb-16">
          <h2 className="text-4xl mb-4">Compétences</h2>
          <p className="text-muted-foreground text-lg">
            Mes domaines d'expertise en réseaux et télécommunications
          </p>
        </div>

        <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-8">
          {skills.map((skill) => {
            const Icon = skill.icon;
            return (
              <div
                key={skill.title}
                className="p-6 rounded-xl bg-card border border-border hover:shadow-lg transition-shadow"
              >
                <div className="w-12 h-12 rounded-lg bg-primary/10 flex items-center justify-center mb-4">
                  <Icon className="w-6 h-6 text-primary" />
                </div>
                <h3 className="text-xl mb-2">{skill.title}</h3>
                <p className="text-muted-foreground">{skill.description}</p>
              </div>
            );
          })}
        </div>
      </div>
    </section>
  );
}
