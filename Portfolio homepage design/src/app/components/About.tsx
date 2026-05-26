import { StarField } from "./StarField";

export function About() {
  return (
    <section id="a-propos" className="min-h-screen flex items-center justify-center bg-gradient-to-br from-primary via-primary/95 to-primary/80 text-primary-foreground px-6 py-20 relative overflow-hidden">
      <StarField />
      <div className="max-w-4xl w-full relative z-10">
        <div className="text-center mb-12">
          <h2 className="text-4xl md:text-5xl mb-4">À propos de moi</h2>
        </div>

        <div className="space-y-6 text-lg text-primary-foreground/90">
          <p>
            Je suis actuellement étudiant en 1ère année de BUT Réseaux et Télécommunications.
            Passionné par le monde des technologies, je m'intéresse particulièrement aux infrastructures
            réseau et à la sécurité informatique.
          </p>

          <p>
            Au-delà de mes études en réseaux, j'ai développé une passion pour le montage vidéo.
            Cette compétence créative me permet de combiner technique et artistique, notamment lors
            de projets comme le concours "Je Filme Ma Formation" où notre équipe a obtenu la 3ème place.
          </p>

          <p>
            Mon objectif est de continuer à développer mes compétences techniques tout en cultivant
            ma créativité. Je suis actuellement à la recherche d'opportunités de stage ou d'alternance
            pour mettre en pratique mes connaissances et contribuer à des projets concrets.
          </p>

          <div className="grid grid-cols-1 md:grid-cols-3 gap-6 mt-12">
            <div className="bg-primary-foreground/10 backdrop-blur-sm rounded-xl p-6 text-center border border-primary-foreground/20">
              <div className="text-3xl mb-2">🎓</div>
              <h3 className="text-xl mb-2">Formation</h3>
              <p className="text-primary-foreground/80">BUT Réseaux et Télécommunications</p>
            </div>

            <div className="bg-primary-foreground/10 backdrop-blur-sm rounded-xl p-6 text-center border border-primary-foreground/20">
              <div className="text-3xl mb-2">💡</div>
              <h3 className="text-xl mb-2">Passions</h3>
              <p className="text-primary-foreground/80">Réseaux, Cybersécurité, Montage Vidéo</p>
            </div>

            <div className="bg-primary-foreground/10 backdrop-blur-sm rounded-xl p-6 text-center border border-primary-foreground/20">
              <div className="text-3xl mb-2">🎯</div>
              <h3 className="text-xl mb-2">Objectif</h3>
              <p className="text-primary-foreground/80">Stage / Alternance en R&T</p>
            </div>
          </div>
        </div>
      </div>
    </section>
  );
}
