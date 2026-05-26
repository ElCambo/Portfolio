import { Mail, Linkedin, Download } from "lucide-react";

export function Contact() {
  return (
    <section id="contact" className="py-20 px-6 bg-background">
      <div className="max-w-4xl mx-auto">
        <div className="text-center mb-16">
          <h2 className="text-4xl mb-4">Contact</h2>
          <p className="text-muted-foreground text-lg">
            N'hésitez pas à me contacter pour toute opportunité ou question
          </p>
        </div>

        <div className="flex flex-wrap justify-center gap-6 max-w-2xl mx-auto">
          <a
            href="mailto:tony.seng@unice.fr"
            className="flex items-start gap-4 p-6 bg-card border border-border rounded-xl hover:shadow-md transition-shadow w-full md:w-[calc(50%-0.75rem)]"
          >
            <div className="w-12 h-12 rounded-lg bg-primary/10 flex items-center justify-center flex-shrink-0">
              <Mail className="w-6 h-6 text-primary" />
            </div>
            <div>
              <h3 className="mb-1">Email</h3>
              <p className="text-muted-foreground">tony.seng@unice.fr</p>
            </div>
          </a>

          <a
            href="https://linkedin.com"
            target="_blank"
            rel="noopener noreferrer"
            className="flex items-start gap-4 p-6 bg-card border border-border rounded-xl hover:shadow-md transition-shadow w-full md:w-[calc(50%-0.75rem)]"
          >
            <div className="w-12 h-12 rounded-lg bg-primary/10 flex items-center justify-center flex-shrink-0">
              <Linkedin className="w-6 h-6 text-primary" />
            </div>
            <div>
              <h3 className="mb-1">LinkedIn</h3>
              <p className="text-muted-foreground">Tony Seng</p>
            </div>
          </a>
        </div>

        <div className="mt-12 p-8 bg-primary/5 border border-primary/20 rounded-xl text-center">
          <p className="text-lg mb-4">
            À la recherche d'un stage ou d'une alternance en réseaux et télécommunications
          </p>
          <div className="flex flex-wrap justify-center gap-4">
            <a
              href="mailto:tony.seng@unice.fr"
              className="inline-flex items-center gap-2 px-8 py-3 bg-primary text-primary-foreground rounded-lg hover:opacity-90 transition-opacity"
            >
              <Mail className="w-5 h-5" />
              Envoyez-moi un message
            </a>
            <a
              href="/cv.pdf"
              download="CV_Tony_Seng.pdf"
              className="inline-flex items-center gap-2 px-8 py-3 bg-primary-foreground text-primary border-2 border-primary rounded-lg hover:opacity-90 transition-opacity"
            >
              <Download className="w-5 h-5" />
              Télécharger mon CV
            </a>
          </div>
        </div>
      </div>
    </section>
  );
}
