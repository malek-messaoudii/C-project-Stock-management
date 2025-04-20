# Gestion de Stock - Système de Suivi des Produits

Un système complet de gestion de stock implémenté en C, avec gestion des catégories, types, produits et statistiques de vente.

## 📋 Fonctionnalités

- **Gestion hiérarchique** :
  - Catégories → Types → Produits
- **Opérations CRUD** :
  - Ajout/Suppression de catégories, types et produits
- **Système de vente intelligent** :
  - Vente des produits par date d'expiration (FIFO)
- **Statistiques** :
  - Ventes par mois/année
  - Analyse par catégorie
- **Persistance** :
  - Journalisation des transactions dans `trace.txt`

## 🛠 Structure du Code
 gestion_stock/
├── src/
│ ├── main.c # Programme principal
│ └── bib.h # Déclarations et fonctions
├── data/
│ └── trace.txt # Fichier de logs des ventes
└── README.md


## 🔧 Installation

### Prérequis
- Compilateur C (gcc recommandé)

### Compilation
```
gcc -o gestion_stock src/main.c
```
### Exécution 
```
gestion_stock.exe
```

